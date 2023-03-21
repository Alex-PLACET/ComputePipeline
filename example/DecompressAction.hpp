#pragma once

#include "Types.hpp"

#include <iostream>

inline std::variant<JSON, RawImage>  DecompressAction(const CompressedData &compressed_data) 
{
    std::cout << "DecompressAction: CompressedData to JSON" << std::endl;
    // Unimplemented: Unzip and detect which type it is.
    // For the example, we detect that it's an image
    return JSON{"{\"name\":\"John\", \"age\":30, \"car\":null}"}; // Generate a fake payload;
};
