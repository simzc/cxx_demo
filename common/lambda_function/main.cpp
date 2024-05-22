#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, const char** argv) {
    std::vector<size_t> test;

    constexpr size_t size = 10;
    for (size_t i = 0; i < size; i++) {
        test.push_back(i);
    }

    auto f = [](auto a, auto b) { return a > b; };

    std::ranges::sort(test, f);

    for (const auto& val : test) {
        std::cout << val << std::endl;
    }

    return 0;
}