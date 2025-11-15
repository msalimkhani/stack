cmake_minimum_required(VERSION 3.10)

project(demo)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBSTACK_PATH "../build")
set(LIBSTACK_INCLUDE "../include")
set(LIBLINKEDLIST_INCLUDE "../linkedlist/include")

include_directories(${LIBLINKEDLIST_INCLUDE} ${LIBSTACK_INCLUDE} ${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

 # Tell the linker where the .so file is
link_directories(${LIBSTACK_PATH})

add_executable(demo ${SRC_FILES})

target_link_libraries(demo PRIVATE stack)