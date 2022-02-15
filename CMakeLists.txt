cmake_minimum_required(VERSION 3.17.3)
project(ft_containers)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_vector includes/containers/ft_vector.hpp catch2/catch.hpp catch2/vector_test.cpp catch2/main.cpp includes/iterators/RandomAccessIterator.hpp includes/iterators/BidirectionalIterator.hpp includes/utils/IteratorUtils.hpp includes/iterators/ReverseIterator.hpp)
add_executable(test_stack includes/containers/ft_stack.hpp includes/containers/ft_vector.hpp catch2/catch.hpp catch2/stack_test.cpp catch2/main.cpp includes/iterators/RandomAccessIterator.hpp includes/iterators/BidirectionalIterator.hpp includes/utils/IteratorUtils.hpp includes/iterators/ReverseIterator.hpp)
add_executable(test_map includes/containers/ft_map.hpp includes/containers/ft_vector.hpp catch2/catch.hpp catch2/map_test.cpp catch2/main.cpp includes/iterators/RandomAccessIterator.hpp includes/iterators/BidirectionalIterator.hpp includes/utils/IteratorUtils.hpp includes/iterators/ReverseIterator.hpp)
add_executable(time_vec timetest/main_vec.cpp includes/containers/ft_vector.hpp includes/iterators/RandomAccessIterator.hpp includes/iterators/BidirectionalIterator.hpp includes/utils/IteratorUtils.hpp includes/iterators/ReverseIterator.hpp includes/containers/ft_stack.hpp includes/utils/AVLtree.hpp includes/utils/ft_pair.hpp includes/utils/utils.hpp)
add_executable(time_sta timetest/main_stack.cpp includes/containers/ft_vector.hpp includes/iterators/RandomAccessIterator.hpp includes/iterators/BidirectionalIterator.hpp includes/utils/IteratorUtils.hpp includes/iterators/ReverseIterator.hpp includes/containers/ft_stack.hpp includes/utils/AVLtree.hpp includes/utils/ft_pair.hpp includes/utils/utils.hpp)
add_executable(time_map timetest/main_map.cpp includes/containers/ft_vector.hpp includes/iterators/RandomAccessIterator.hpp includes/iterators/BidirectionalIterator.hpp includes/utils/IteratorUtils.hpp includes/iterators/ReverseIterator.hpp includes/containers/ft_stack.hpp includes/utils/AVLtree.hpp includes/utils/ft_pair.hpp includes/utils/utils.hpp)
include_directories(includes)
add_subdirectory(catch2)