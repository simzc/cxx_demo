cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

project(demo LANGUAGES CXX)

#-----------------------------------------------------------------------------
# Detect operating system and processor for host and target
#-----------------------------------------------------------------------------
message(STATUS "We are on a ${CMAKE_HOST_SYSTEM_NAME} system")
message(STATUS "The host processor is ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "Building for a ${CMAKE_SYSTEM_NAME} system")
message(STATUS "The target processor is ${CMAKE_SYSTEM_PROCESSOR}")

if (MSVC OR XCODE_VERSION)
    set(CMAKE_CONFIGURATION_TYPES Release CACHE STRING "Choose the type of build.")
    set_property(CACHE CMAKE_CONFIGURATION_TYPES PROPERTY STRINGS Debug Release MinSizeRel RelWithDebInfo)
    mark_as_advanced(FORCE CMAKE_BUILD_TYPE)
    mark_as_advanced(CLEAR CMAKE_CONFIGURATION_TYPES)
    set(CPACK_BUILD_TYPE ${CMAKE_CONFIGURATION_TYPES})
else ()
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build.")
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release MinSizeRel RelWithDebInfo)
    set(CPACK_BUILD_TYPE ${CMAKE_BUILD_TYPE})
endif ()

# CMake module path
LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(Common)

option(enable_cuda "Enable cuda environment." OFF)
if (enable_cuda)
    enable_language(CUDA)
    message(STATUS "CUDA support is enabled.")

    # Find CUDA toolkit
    find_package(CUDAToolkit REQUIRED)

    # Global fix for CUDA language bug
    include_directories(${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})
    message(STATUS "CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES is : ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}.")
endif (enable_cuda)

# Set CXX standard
set(DEMO_CXX_STD "20")
message(STATUS "DEMO_CXX_STD is: ${DEMO_CXX_STD}.")

# Set CXX and CUDA flags for demos
set(DEMO_CXX_FLAGS "")
list(APPEND DEMO_CXX_FLAGS ${CMAKE_CXX_FLAGS})
if (enable_cuda)
    set(DEMO_CUDA_FLAGS "")
    list(APPEND DEMO_CUDA_FLAGS ${CMAKE_CUDA_FLAGS})
endif ()

# Debug option
if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    message(STATUS "Debug mode is ON")
    list(APPEND DEMO_CXX_FLAGS "-g")
    if (enable_cuda)
        list(APPEND DEMO_CUDA_FLAGS "-G")
    endif ()
endif ()

# Printing configuration
message(STATUS "DEMO_CXX_FLAGS is ${DEMO_CXX_FLAGS}")
if (enable_cuda)
    message(STATUS "DEMO_CUDA_FLAGS is ${DEMO_CUDA_FLAGS}")
endif ()

message(STATUS "CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CUDA_FLAGS is ${CMAKE_CUDA_FLAGS}")

# Demo run on the host
add_subdirectory(common)
add_subdirectory(generic_programming)
add_subdirectory(stl)

# Demo run on device
if (enable_cuda)
    add_subdirectory(cuda)
endif (enable_cuda)
