cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 11)

add_executable(ft_containers includes/Vector.hpp test/catch.hpp test/vector_test.cpp test/main.cpp includes/OutputIterator.hpp includes/Iterator.hpp)
include_directories(includes)
add_subdirectory(test)