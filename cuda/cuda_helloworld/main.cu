#include <iostream>
#include "vector_types.h"

__global__ void HelloWorldCuk() {
    printf("Hello World on device!\n");
}

int main(int argc, const char** argv) {
    // Invoking the kernel function
    HelloWorldCuk<<<1, 1>>>();

    cudaDeviceSynchronize();
    
    return 0;
}