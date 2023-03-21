#pragma once

#include <any>
#include <concepts>
#include <cstdint>
#include <functional>
#include <stdexcept>
#include <typeindex>
#include <unordered_map>
#include <variant>

namespace ComputePipeline {

template <typename V>
concept is_variant = requires(V v) { []<typename... Ts>(std::variant<Ts...> const &) {}(v); };

template <typename InputTypeForCompute>
class ComputePipeline {
public:
  template <typename ReturnType>
  explicit ComputePipeline(ReturnType (*fPtr)(InputTypeForCompute)) {
    addAction(*fPtr);
  }

  template <typename ReturnType, typename ArgType>
  void addAction(ReturnType (*fPtr)(ArgType)) {
    const std::type_index key(typeid(ArgType));
    const auto value = [fPtr](std::any arg) -> std::any {
      const auto &arg_casted = std::any_cast<ArgType>(arg);
      if constexpr (std::is_same_v<ReturnType, void>) {
        fPtr(arg_casted);
        return 0;
      } else if constexpr (is_variant<ReturnType>) {
        auto variant = fPtr(arg_casted);
        return std::visit(
            [](auto &&variant_value) {
              return std::any(std::forward<decltype(variant_value)>(variant_value));
            },
            std::move(variant));
      } else {
        return fPtr(arg_casted);
      }
    };
    const auto [iterator, is_inserted] = actions_by_input_arg.try_emplace(key, value);
    if (!is_inserted) {
      throw std::runtime_error("An action which takes a " +
                               std::string(key.name()) +
                               " as argument has already been added.");
    }
  }

  std::any compute(const InputTypeForCompute& input) {
    // First round with the initial action.
    std::any output_input = actions_by_input_arg.at(std::type_index(typeid(InputTypeForCompute)))(input);
    std::type_index type_idx(output_input.type());
    auto action = actions_by_input_arg.find(type_idx);
    // Then we iterate until no action get the output type as parameter type.
    while (action != actions_by_input_arg.end()) {
      output_input = action->second(output_input);
      type_idx = output_input.type();
      action = actions_by_input_arg.find(type_idx);
    }
    return output_input;
  }

private:
  std::unordered_map<std::type_index, std::function<std::any(std::any)>> actions_by_input_arg;
};

}
