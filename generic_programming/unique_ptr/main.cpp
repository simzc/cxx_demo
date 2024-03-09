#include <utility>
#include <iostream>

class Test {
  public:
    Test() { std::cout << "Test() constructed." << std::endl; }
    ~Test() { std::cout << "Test() destructed." << std::endl; }

    void Show() const { std::cout << "Hello World!" << std::endl; }
};

/// @brief Unique pointer manager for Type of object
/// @tparam Type Type of object
template <typename Type>
class UniquePtr {
  public:
    /// @brief Default constructor
    UniquePtr() : m_ptr(nullptr) { std::cout << "Default constructor invoked." << std::endl; }

    /// @brief Constructor with initial pointer
    UniquePtr(Type* ptr) : m_ptr(ptr) { std::cout << "Constructor invoked." << std::endl; }

    /// @brief Deleted copy constructor
    UniquePtr(const UniquePtr&) = delete;

    /// @brief Deleted assignment operator
    UniquePtr& operator=(const UniquePtr&) = delete;

    /// @brief Move constructor
    /// @param rhs Rvalue of object
    UniquePtr(UniquePtr&& rhs) noexcept : m_ptr(std::exchange(rhs.m_ptr, nullptr)) {
        std::cout << "Move constructor invoked." << std::endl;
    }

    /// @brief Move assignment constructor
    /// @param rhs Rvalue of object
    UniquePtr& operator=(UniquePtr&& rhs) noexcept {
        std::cout << "Move assignment operator invoked." << std::endl;
        std::swap(m_ptr, rhs.m_ptr);
        return *this;
    }

    /// @brief Destructor
    ~UniquePtr() {
        if (m_ptr) {
            delete m_ptr;
            m_ptr = nullptr;
        }
    }

    /// @brief Get the pointer of object
    Type*& Get() { return m_ptr; }

    /// @brief Reload operator of ->
    Type*& operator->() { return m_ptr; }

    /// @brief Reload operator of *
    Type& operator*() { return *m_ptr; }

  private:
    Type* m_ptr;
};

int main(int argc, const char** argv) {
    UniquePtr<Test> test_1 = new Test();
    UniquePtr<Test> test_2 = std::move(test_1);
    UniquePtr<Test> test_3 = static_cast<UniquePtr<Test>&&>(test_2);

    test_3->Show();
    test_3.Get()->Show();
    (*test_3).Show();

    std::cout << "Unique pointer ending." << std::endl;

    return 0;
}