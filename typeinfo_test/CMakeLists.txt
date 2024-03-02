set(target_name "typeinfo_test")

add_executable(${target_name} main.cpp)

target_compile_features(${target_name} PRIVATE ${demo_cxx_std})