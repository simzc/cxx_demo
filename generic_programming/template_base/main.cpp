#include <string>
#include <type_traits>
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

#if 0
/// @brief Multi-parameter template
template<typename T1, typename T2, typename T3>
T3 foo(const T1& x, const T2& y) {
    return x + y;
}

/// @brief Multi-parameter template (C++ 17)
template<typename T1, typename T2>
auto foo(const T1& x, const T2& y) -> decltype(x+y) {
    return x + y;
}

#endif // end if macro

/// @brief Multi-parameter template (C++ 20 with Concept)
auto foo(const auto& x, const auto& y) {
    return x + y;
}

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

    // Multi-parameter template
    {
        std::string a = "hello";
        std::string b = " world!";
        std::cout << foo(a, b) << std::endl;
    }

    return 0;
}