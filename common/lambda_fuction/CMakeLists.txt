set(target_name "lambda_fuction")

message(STATUS "added demo ${target_name}.")

add_executable(${target_name} main.cpp)

target_compile_features(${target_name} PRIVATE ${demo_cxx_std})