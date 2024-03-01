set(target_name "decay_type")

add_executable(${target_name} main.cpp)

target_compile_features(${target_name} PRIVATE ${demo_cxx_std})