set(target_name "unique_ptr")

message(STATUS "added demo ${target_name}.")

add_executable(${target_name} main.cpp)

set_target_properties(${target_name} PROPERTIES CXX_STANDARD ${DEMO_CXX_STD})
set_target_properties(${target_name} PROPERTIES CXX_STANDARD_REQUIRED ON)