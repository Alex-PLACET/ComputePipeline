set(SOURCES
    main.cpp)

add_executable(Example ${SOURCES})

target_link_libraries(Example 
    PRIVATE 
        ComputePipeline)