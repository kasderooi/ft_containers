project(test)

set(CMAKE_CXX_STANDARD 11)
include_directories(../includes)
add_executable(test catch.hpp main.cpp vector_test.cpp)