cmake_minimum_required(VERSION 2.8)
project(binary_search_tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES source/binary_search_tree.cpp include/binary_search_tree.h)
add_executable(binary_search_tree ${SOURCE_FILES} examples/main.cpp )
