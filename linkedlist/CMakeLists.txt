cmake_minimum_required(VERSION 3.10)
project(liblinkedlist LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(linkedlist INTERFACE)

target_include_directories(linkedlist INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
