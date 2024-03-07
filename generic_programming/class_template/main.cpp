#include <iostream>

template <typename Type, size_t N>
class Array {
  public:
    /// @brief Get the value by index
    /// @param num Index
    /// @return Value
    Type& operator[](size_t num) {
        if (num < N) {
            return m_val[num];
        }
        throw "Out of the range.";
    }

    /// @brief Get the size of array
    size_t size() const { return N; }

  private:
    Type m_val[N];
};

int main(int argc, const char** argv) {
    Array<int, 10> array;
    for (size_t i = 0; i < array.size(); i++) {
        array[i] = i;
    }

    std::cout << "The size of array is: " << array.size() << std::endl;

    for (size_t i = 0; i < array.size(); i++) {
        std::cout << "array[" << i << "] is: " << array[i] << std::endl;
    }

    return 0;
}