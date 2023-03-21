#pragma once

#include "Types.hpp"

#include <string_view>
#include <variant>
#include <stdexcept>
#include <iostream>

inline std::variant<CompressedData, RawImage, JSON> LoadAction(std::string_view URI) {
  // Determine the type of URI and load the item accordingly.
  // I use CompressedData for the example, but we detect should which type of data it is thanks to the file extension.
  if (URI.starts_with("file://")) {     // Load from file
    std::cout << "LoadAction: URI to CompressedData" << std::endl;
    return CompressedData{std::vector<uint8_t>(100,0)}; 
  } else if (URI.starts_with("http://") || URI.starts_with("https://")) {     // Load from URL
    std::cout << "LoadAction: URI to RawImage" << std::endl;
    return RawImage{std::vector<uint8_t>(100,0)};
  } else if (URI.starts_with("bundle://")) { // Load from application bundle
    std::cout << "LoadAction: URI to JSON" << std::endl;
    return JSON{R"({"name":"John", "age":30, "car":null})"};
  }
  throw std::invalid_argument("The provided URI is not supported by the LoadAction.");
}

