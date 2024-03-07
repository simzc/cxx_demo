set(target_name "cuda_helloworld")

message(STATUS "added demo ${target_name}.")

add_executable(${target_name} main.cu)

set_target_properties(${target_name} PROPERTIES CXX_STANDARD ${DEMO_CXX_STD})
set_target_properties(${target_name} PROPERTIES CXX_STANDARD_REQUIRED ON)