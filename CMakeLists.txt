cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(ComputePipeline
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(library)
add_subdirectory(example)
