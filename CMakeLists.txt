cmake_minimum_required(VERSION 3.19.2)
project(ft_containers)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_vector includes/ft_vector.hpp test/catch.hpp test/vector_test.cpp test/main.cpp includes/RandomAccessIterator.hpp includes/IteratorUtils.hpp includes/ReverseIterator.hpp)
add_executable(smalltest srcs/main.cpp includes/ft_vector.hpp includes/RandomAccessIterator.hpp includes/IteratorUtils.hpp includes/ReverseIterator.hpp includes/ft_stack.hpp)
include_directories(includes)
add_subdirectory(test)