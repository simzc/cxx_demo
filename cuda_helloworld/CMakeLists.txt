set(target_name "cuda_helloworld")

add_executable(${target_name} main.cu)

target_compile_features(${target_name} PRIVATE ${demo_cxx_std})