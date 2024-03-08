
#include <utility>
#include <iostream>

class Test {
  public:
    Test() { std::cout << "Test() constructed." << std::endl; }
    ~Test() { std::cout << "Test() destructed." << std::endl; }
};

template <typename Type>
class UniquePtr {
  public:
    UniquePtr() : m_ptr(nullptr) {
        std::cout << "Default constructor invoked." << std::endl;
    }

    UniquePtr(Type* ptr) : m_ptr(ptr) {
        std::cout << "Constructor invoked." << std::endl;
    }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& rhs) : m_ptr(std::exchange(rhs.m_ptr, nullptr)) {
        std::cout << "Move constructor invoked." << std::endl;
    }

    UniquePtr& operator=(UniquePtr&& rhs) {
        std::cout << "Move assignment operator invoked." << std::endl;
        std::swap(m_ptr, rhs.m_ptr);
        return *this;
    }

    ~UniquePtr() {
        if (m_ptr) {
            delete m_ptr;
            m_ptr = nullptr;
        }
    }

  private:
    Type* m_ptr;
};

int main(int argc, const char** argv) {
    UniquePtr<Test> test_1 = new Test();
    UniquePtr<Test> test_2 = std::move(test_1);
    UniquePtr<Test> test_3 = static_cast<UniquePtr<Test>&&>(test_2);

    std::cout << "Unique pointer ending." << std::endl;

    return 0;
}