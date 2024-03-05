#include <iostream>

/// @brief Template function
/// @tparam Type
/// @param x
/// @param y
/// @return
template <typename Type>
Type add(Type x, Type y) {
    return x + y;
}

/// @brief Template class
/// @tparam Type
template <typename Type>
struct StructAbs {
    Type _val;
};

/// @brief Template param with size_t
/// @tparam type 
template <auto type>
constexpr auto const_v = type;

int main(int argc, const char** argv) {
    // Template function
    {
        auto result_1 = add(1, 2);
        auto result_2 = add(1., 2.);
    }

    // Template class
    {
        StructAbs<int> barz;
        barz._val = 2;
    }

    // Template param with auto (C++ 17)
    {
        auto v1 = const_v<1>;
        auto v2 = const_v<true>;
        auto v3 = const_v<'a'>;

        std::cout << v1 << std::endl;
        std::cout << v2 << std::endl;
        std::cout << v3 << std::endl;
    }

    return 0;
}