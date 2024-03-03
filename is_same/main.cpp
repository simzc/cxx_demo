#include <iostream>
#include <type_traits>
#include <typeinfo>

int main(int argc, const char** argv) {
    std::cout << std::boolalpha;

    {
        // Basic type
        constexpr bool v1 = std::is_same<double, double>::value;
        std::cout << "v1: " << v1 << std::endl;

        // Using decltype
        constexpr bool v2 = std::is_same<double, decltype(2 + 1.5)>::value;
        std::cout << "v2: " << v2 << std::endl;

        double a = 0.;
        constexpr bool v3 = std::is_same<double, decltype(a)>::value;
        std::cout << "v3: " << v3 << std::endl;

        const auto& b = a;
        constexpr bool v4 = std::is_same<double, decltype(b)>::value;
        std::cout << "v4: " << v4 << std::endl;

        // Type conversion using std::decay
        constexpr bool v5 = std::is_same<double, std::decay_t<decltype(b)>>::value;
        std::cout << "v5: " << v5 << std::endl;
    }

    std::cout << std::endl;

    {
        const bool v1 = typeid(double) == typeid(double);
        std::cout << "v1: " << v1 << std::endl;

        const bool v2 = typeid(double) == typeid(0.);
        std::cout << "v2: " << v2 << std::endl;

        double a = 0.;
        const bool v3 = typeid(double) == typeid(a);
        std::cout << "v3: " << v3 << std::endl;

        const double& b = a;
        const bool v4 = typeid(double) == typeid(b);
        std::cout << "v4: " << v4 << std::endl;
    }

    std::cout << std::endl;

    // clang-format off
    std::cout << "std::is_same_v<int, std::int32_t> is: "   << std::is_same_v<int, std::int32_t>   << std::endl;
    std::cout << "std::is_same_v<int, std::int64_t> is: "   << std::is_same_v<int, std::int64_t>   << std::endl;
    std::cout << "std::is_same_v<float, std::int32_t> is: " << std::is_same_v<float, std::int32_t> << std::endl;
    // clang-format on

    std::cout << std::endl;

    // clang-format off
    std::cout << "std::is_same_v<int, int> is: "          << std::is_same_v<int, int>          << std::endl;
    std::cout << "std::is_same_v<int, unsigned int> is: " << std::is_same_v<int, unsigned int> << std::endl;
    std::cout << "std::is_same_v<int, signed int> is: "   << std::is_same_v<int, signed int>   << std::endl;
    // clang-format on

    std::cout << std::endl;

    // clang-format off
    std::cout << "std::is_same_v<char, char> is: "          << std::is_same_v<char, char>          << std::endl;
    std::cout << "std::is_same_v<char, unsigned char> is: " << std::is_same_v<char, unsigned char> << std::endl;
    std::cout << "std::is_same_v<char, signed char> is: "   << std::is_same_v<char, signed char>   << std::endl;
    // clang-format on

    return 0;
}