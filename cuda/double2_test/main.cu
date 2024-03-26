#include <iostream>
#include <array>
#include <vector>
#include "vector_types.h"

struct MyStruct {
    std::vector<std::array<double, 2>> array_a;
};

int main(int argc, const char** argv) {
    std::vector<double2> test_a;
    test_a.resize(5);
    for (auto& var : test_a) {
        var = make_double2(1.0, 2.0);
    }

    std::vector<double2> test_b;
    test_b = test_a;

    for (auto& var : test_b) {
        std::cout << "var.x: " << var.x << "\t"
                  << "var.y: " << var.y << std::endl;
    }

    // std::vector<std::array<double, 2>> array_a = {{1., 2.}, {3., 4.}};
    std::vector<std::array<double, 2>> array_a;
    // std::vector<std::array<double, 2>> array_b;

    // array_b = array_a;
    // for (auto& var : array_b) {
    //     std::cout << "array[0]: " << var.at(0) << "\t"
    //               << "array[1]: " << var.at(1) << std::endl;
    // }

    MyStruct struct_a;
    struct_a.array_a = array_a;

    MyStruct struct_b;
    struct_b = struct_a;

    return 0;
}