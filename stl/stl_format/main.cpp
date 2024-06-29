#include <iostream>
#include <format>

int main(int argc, const char** argv) {

    std::cout << "__cplusplus" << __cplusplus<< std::endl;

    size_t i{};
    std::cout << std::format("i = {}", i) << "\n";

    return 0;
}