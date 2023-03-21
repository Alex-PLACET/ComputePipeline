#pragma once

#include <string>
#include <vector>
#include <optional>

struct ARandomObject {
  std::string name;
  uint8_t age;
  std::optional<std::string> car_brand;
};
