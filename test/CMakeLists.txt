project(test)

set(CMAKE_CXX_STANDARD 11)
include_directories(../includes)
add_executable(test_vec catch.hpp main.cpp vector_test.cpp)