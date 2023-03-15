cmake_minimum_required(VERSION 3.0)
project(MatrixTests)

# Add the Matrix class implementation
add_library(Matrix src/matrixClass.cpp)

# Add the test executable
add_executable(tests src/tests.cpp)

# Link the Matrix class library with the test executable
target_link_libraries(tests Matrix)

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Link Google Test with the test executable
target_link_libraries(tests gtest gtest_main)

# Set C++ standard to C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)