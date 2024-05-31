#include <iostream>

__global__ void HelloWorldCuk() {
    unsigned int tid = threadIdx.x + blockDim.x * blockIdx.x;
    if (tid == 0) {
        printf("Hello World on device!\n");
    }
}

int main(int argc, const char** argv) {
    // Invoking the kernel function
    HelloWorldCuk<<<1, 1>>>();

    cudaDeviceSynchronize();

    return 0;
}