cmake_minimum_required(VERSION 3.10)
project(stack)

add_subdirectory(linkedlist)
add_subdirectory(demo)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to mylib.so and headers
set(LIBLINKEDLIST_PATH "linkedlist/build")
set(LIBLINKEDLIST_INCLUDE "linkedlist/include")

# Add include directory
include_directories(${LIBLINKEDLIST_INCLUDE} ${CMAKE_SOURCE_DIR}/include)

 file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Tell the linker where the .so file is
link_directories(${CMAKE_BINARY_DIR}/${LIBLINKEDLIST_PATH})

add_library(stack SHARED ${SRC_FILES})
target_link_libraries(stack PRIVATE linkedlist)
