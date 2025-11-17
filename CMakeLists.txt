cmake_minimum_required(VERSION 3.10)
project(stack CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(tools)
add_subdirectory(linkedlist)
add_subdirectory(demo)

add_library(stack INTERFACE)

target_include_directories(stack INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
        )
target_link_libraries(stack INTERFACE linkedlist)
