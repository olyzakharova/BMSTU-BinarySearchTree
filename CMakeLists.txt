cmake_minimum_required(VERSION 2.8)
project(binary_search_tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(TESTS_SOURCE tests/main.cpp tests/find.cpp tests/insert.cpp tests/size.cpp tests/catch.hpp tests/remove.cpp)
set(SOURCE_FILES source/binary_search_tree.cpp include/binary_search_tree.h)

include_directories(include)
add_executable(binary_search_tree ${SOURCE_FILES} examples/main.cpp )
add_executable(Tests ${TESTS_SOURCE} tests/main.cpp)
