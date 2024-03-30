#include <array>
#include <iostream>

template <typename Value, typename Type>
class Iteration {
  public:
    Iteration(Value* ptr, size_t idx) {
        m_ptr = ptr;
        m_idx = idx;
    }

    Type& operator*() { return (*m_ptr)[m_idx]; }

    Iteration& operator++() {
        m_idx++;
        return *this;
    }

    bool operator!=(const Iteration& rhs) { return rhs.m_idx != this->m_idx; }

  private:
    Value* m_ptr = nullptr;
    size_t m_idx = 0;
};

template <typename Type, size_t size>
class Array {
  public:
    using iteration = Iteration<Array<Type, size>, Type>;

  public:
    Type m_data[size];

    Type& operator[](const size_t idx) { return m_data[idx]; }

    size_t Size() const { return size; }

    iteration begin() { return iteration(this, 0); }

    iteration end() { return iteration(this, size); }
};

int main(int argc, const char** argv) {
    Array<int, 5> data = {0, 1, 2, 3, 4};

    std::cout << data.Size() << std::endl;

    std::cout << data[2] << std::endl;

    for (const auto& i : data) {
        std::cout << i << std::endl;
    }

    return 0;
}