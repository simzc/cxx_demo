#include <iostream>
#include <type_traits>

/// @brief Equal to std::is_same<std::decay_t<T>, U>::type
/// @tparam T Type conversion
/// @tparam U Argument passed by value
template <typename T, typename U>
struct decay_equal_t : std::is_same<typename std::decay<T>::type, U>::type {};

/// @brief Print the type info
/// @tparam Type Original type
template <typename Type>
void PrintDecayType() {
    std::cout << "Original type: " << typeid(Type).name() << std::endl;
    std::cout << "Decayed type: " << typeid(std::decay_t<Type>).name() << std::endl;
}

void foo() {
    std::cout << "foo() invoking..." << std::endl;
}

int main(int argc, const char** argv) {
    // clang-format off
    std::cout << std::boolalpha 
              << decay_equal_t<int, int>::value              << std::endl
              << decay_equal_t<int&, int>::value             << std::endl
              << decay_equal_t<int&&, int>::value            << std::endl
              << decay_equal_t<const int&, int>::value       << std::endl
              << decay_equal_t<int[2], int*>::value          << std::endl
              << decay_equal_t<int(int), int(*)(int)>::value << std::endl
              << std::endl;
    // clang-format on

    /////////////////////////////////////////////////////////////////////////////////////
    // Print the original and decayed type info

    // Int type
    std::cout << "Int type" << std::endl;
    PrintDecayType<decltype(1)>();
    std::cout << std::endl;

    // Float type
    std::cout << "Float type" << std::endl;
    PrintDecayType<decltype(1.0f)>();
    std::cout << std::endl;

    // Double type
    std::cout << "Double type" << std::endl;
    PrintDecayType<decltype(2.0)>();
    std::cout << std::endl;

    // Array => Ptr
    int array[5] = {1, 2, 3, 4, 5};
    PrintDecayType<decltype(array)>();
    std::cout << std::endl;

    // Function type
    PrintDecayType<decltype(foo)>();
    std::cout << std::endl;

    void (*fptr)() = foo;
    fptr();

    return 0;
}