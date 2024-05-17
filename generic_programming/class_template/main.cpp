#include <iostream>

template <typename Type, size_t N>
class Array {
  public:
    /// @brief Default constructor
    Array() = default;

    /// @brief Constructor with initial value
    /// @param val Filled value
    explicit Array(Type val) {
        for (size_t i = 0; i < N; i++) {
            m_val[i] = val;
        }
    }

    /// @brief Get the value by index
    /// @param num Index
    /// @return Value
    Type& operator[](size_t num) {
        if (num < N) {
            return m_val[num];
        }
        throw R"(Out of the range.)";
    }

    /// @brief Get the size of array
    size_t size() const { return N; }

  private:
    Type m_val[N];
};

int main(int argc, const char** argv) {
    Array<int, 10> array_a{};
    for (size_t i = 0; i < array_a.size(); i++) {
        array_a[i] = i;
    }

    std::cout << "The size of array is: " << array_a.size() << std::endl;

    for (size_t i = 0; i < array_a.size(); i++) {
        std::cout << "array[" << i << "] is: " << array_a[i] << std::endl;
    }

    std::cout << std::endl;

    Array<int, 10> array_b(10);
    std::cout << "The size of array is: " << array_b.size() << std::endl;

    for (size_t i = 0; i < array_b.size(); i++) {
        std::cout << "array[" << i << "] is: " << array_b[i] << std::endl;
    }

    return 0;
}