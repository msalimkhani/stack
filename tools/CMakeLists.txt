cmake_minimum_required(VERSION 3.10)
project(libtools CXX)
add_library(tools INTERFACE)

target_include_directories(tools INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
message(STATUS "tools include: ${CMAKE_CURRENT_SOURCE_DIR}/include")