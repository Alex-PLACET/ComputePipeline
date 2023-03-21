#pragma once

#include <any>
#include <cstdint>
#include <string>
#include <variant>
#include <vector>
#include <any>

struct RawImage {
  std::vector<uint8_t> data;
};

struct Image {
  std::vector<uint8_t> data;
};

struct CompressedData {
  std::vector<uint8_t> data;
};

struct JSON {
  std::string data;
};
