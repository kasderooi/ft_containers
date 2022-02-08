cmake_minimum_required(VERSION 3.17.3)
project(ft_containers)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_vector includes/ft_vector.hpp test/catch.hpp test/vector_test.cpp test/main.cpp includes/RandomAccessIterator.hpp includes/BidirectionalIterator.hpp includes/IteratorUtils.hpp includes/ReverseIterator.hpp)
add_executable(test_stack includes/ft_stack.hpp includes/ft_vector.hpp test/catch.hpp test/stack_test.cpp test/main.cpp includes/RandomAccessIterator.hpp includes/BidirectionalIterator.hpp includes/IteratorUtils.hpp includes/ReverseIterator.hpp)
add_executable(test_map includes/ft_map.hpp includes/ft_vector.hpp test/catch.hpp test/map_test.cpp test/main.cpp includes/RandomAccessIterator.hpp includes/BidirectionalIterator.hpp includes/IteratorUtils.hpp includes/ReverseIterator.hpp)
add_executable(smalltest srcs/main.cpp includes/ft_vector.hpp includes/RandomAccessIterator.hpp includes/BidirectionalIterator.hpp includes/IteratorUtils.hpp includes/ReverseIterator.hpp includes/ft_stack.hpp includes/AVLtree.hpp includes/ft_pair.hpp includes/utils.hpp includes/NodeIterator.hpp)
include_directories(includes)
add_subdirectory(test)