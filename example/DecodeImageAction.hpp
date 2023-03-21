#pragma once

#include "Types.hpp"

#include <iostream>

inline Image DecodeImageAction(const RawImage &raw_image) 
{
    std::cout << "DecodeImageAction: RawImage to Image" << std::endl;
    // Unimplemented: Doing stuff with raw_data.data
    return Image{std::vector<uint8_t>(100,0)}; // Generate a fake payload;
};

