cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

project(demo LANGUAGES CXX)

# CUDA is not enabled on MacOS
set(enable_cuda OFF)
if(NOT CMAKE_SYSTEM_NAME MATCHES "Darwin")
    enable_language(CUDA)
    set(enable_cuda ON)
    message(STATUS "CUDA support is enabled.")

    # Find CUDA toolkit
    find_package(CUDAToolkit REQUIRED)

    # Global fix for CUDA language bug
    include_directories(${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})
    message(STATUS "CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES is : ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}.")
endif(NOT CMAKE_SYSTEM_NAME MATCHES "Darwin")


# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(demo_cxx_std "cxx_std_20")

# Demo run on the host
add_subdirectory(decay_type)
add_subdirectory(functor_test)
add_subdirectory(is_same)
add_subdirectory(lambda_fuction)
add_subdirectory(source_location)
add_subdirectory(typeinfo_test)
add_subdirectory(variant_test)

# Demo run on device
if(enable_cuda)
    add_subdirectory(cuda_helloworld)    
endif(enable_cuda)
