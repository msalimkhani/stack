project(demo)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBSTACK_INCLUDE "../include")
set(LIBLINKEDLIST_INCLUDE "../linkedlist/include")

include_directories(${LIBLINKEDLIST_INCLUDE} ${LIBSTACK_INCLUDE} ${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(demo ${SRC_FILES})

# Link against the top-level interface target so its usage requirements
# (include directories from linkedlist -> tools) propagate to this exe.
target_link_libraries(demo PRIVATE stack)