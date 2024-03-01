cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

project(demo LANGUAGES CXX CUDA)

# Find CUDA toolkit
find_package(CUDAToolkit REQUIRED)

# Global fix for CUDA language bug
include_directories(${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})
message(STATUS "CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES is : ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}.")


# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(demo_cxx_std "cxx_std_20")

add_subdirectory(cuda_helloworld)
add_subdirectory(functor_test)
add_subdirectory(lambda_fuction)
add_subdirectory(source_location)
add_subdirectory(variant_test)