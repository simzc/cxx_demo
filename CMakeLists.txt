cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

project(demo LANGUAGES CXX)

option(enable_cuda "Enabale cuda environment." OFF)
if(enable_cuda)
    enable_language(CUDA)
    message(STATUS "CUDA support is enabled.")

    # Find CUDA toolkit
    find_package(CUDAToolkit REQUIRED)

    # Global fix for CUDA language bug
    include_directories(${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})
    message(STATUS "CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES is : ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}.")
endif(enable_cuda)

# Set CXX standard
set(DEMO_CXX_STD "20")
message(STATUS "DEMO_CXX_STD is: ${DEMO_CXX_STD}.")

# Demo run on the host
add_subdirectory(common)
add_subdirectory(generic_programming)
add_subdirectory(stl)

# Demo run on device
if(enable_cuda)
    add_subdirectory(cuda)    
endif(enable_cuda)
