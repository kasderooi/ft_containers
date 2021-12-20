cmake_minimum_required(VERSION 3.19.2)
project(ft_containers)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} includes/ft_vector.hpp test/catch.hpp test/vector_test.cpp test/main.cpp includes/RandomAccesIterator.hpp includes/IteratorUtils.hpp includes/ReverseIterator.hpp)
add_executable(smalltest srcs/main.cpp includes/ft_vector.hpp includes/RandomAccesIterator.hpp includes/IteratorUtils.hpp includes/ReverseIterator.hpp)
include_directories(includes)
add_subdirectory(test)