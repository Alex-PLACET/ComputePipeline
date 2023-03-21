#pragma once

#include "Types.hpp"
#include "ARandomObject.hpp"

#include <any>
#include <iostream>

inline std::any DeserializeJSONAction(const JSON &json) 
{
    std::cout << "DeserializeJSONAction: JSON to ARandomObject" << std::endl;
    // Unimplemented: Doing stuff with raw_data.data
    return ARandomObject{"John", 32, "Ford"}; // Generate a fake payload;
};
