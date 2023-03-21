set(HEADERS_PATH headers/ComputePipeline)

set(HEADERS 
    ${HEADERS_PATH}/ComputePipeline.hpp)

add_library(ComputePipeline INTERFACE ${HEADERS})
target_include_directories(ComputePipeline
    INTERFACE
        headers)
