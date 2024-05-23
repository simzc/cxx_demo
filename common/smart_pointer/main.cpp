#include <vector>
#include <memory>
#include <iostream>
#include <type_traits>

/// @brief Check if a class has a custom new operator
template <class T>
class class_has_custom_new_operator {
    template <typename C>
    static inline char test(decltype(C::operator new(sizeof(C))));
    template <typename C>
    static inline long test(...);

  public:
    enum { value = sizeof(test<T>(nullptr)) == sizeof(char) };
};

template <class T>
using SharedPtr = std::shared_ptr<T>;

template <class T>
using UniquePtr = std::unique_ptr<T>;

template <class T>
using WeakPtr = std::weak_ptr<T>;

// ===================================================================
// Make std::shared_ptr<T>
// ===================================================================

// C++14 version = make_shared for class with overriden operator new.
template <typename T, typename... Args, std::enable_if_t<class_has_custom_new_operator<T>::value, int> = 0>
inline SharedPtr<T> make_shared(Args&&... args) {
    return std::make_shared<T>(new T(std::forward<Args>(args)...));
}

// C++14 version = make_shared for class with no overriden operator new.
template <typename T, typename... Args, std::enable_if_t<!class_has_custom_new_operator<T>::value, int> = 0>
inline SharedPtr<T> make_shared(Args&&... args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

// C++14 version = make_unique for class with overriden operator new.
template <typename T, typename... Args, std::enable_if_t<class_has_custom_new_operator<T>::value, int> = 0>
inline UniquePtr<T> make_unique(Args&&... args) {
    return std::make_unique<T>(new T(std::forward<Args>(args)...));
}

// C++14 version = make_unique for class with no overriden operator new.
template <typename T, typename... Args, std::enable_if_t<!class_has_custom_new_operator<T>::value, int> = 0>
inline UniquePtr<T> make_unique(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

class Base {
  public:
    Base() { std::cout << "Base constructor invoking..." << std::endl; }
    virtual ~Base() { std::cout << "Base destructor invoking..." << std::endl; }
};

class DerivedWithoutNew : public Base {
  public:
    DerivedWithoutNew() { std::cout << "DerivedWithoutNew contructor invoking... " << std::endl; }
    ~DerivedWithoutNew() { std::cout << "DerivedWithoutNew destructor invoking... " << std::endl; }
};

class DerivedWithNew : public Base {
  public:
    DerivedWithNew() { std::cout << "DerivedWithNew contructor invoking... " << std::endl; }
    ~DerivedWithNew() { std::cout << "DerivedWithNew destructor invoking... " << std::endl; }

    void* operator new(size_t size, void* ptr) {
        std::cout << "Custom new operator with pointer invoking... " << std::endl;
        return ptr;
    }

    void operator delete(void* ptr) {}
};

int main(int argc, const char** argv) {
    std::vector<SharedPtr<Base>> base_lists;

    std::cout << std::endl;
    std::cout << "// =============================================================" << std::endl;
    std::cout << "Testing DerivedWithoutNew..." << std::endl;
    std::cout << "// =============================================================" << std::endl;
    std::cout << std::endl;

    auto ptr_1 = make_shared<DerivedWithoutNew>();

    {
        auto ptr_2 = ptr_1;
        std::cout << "The counts of shared pointer is: " << ptr_1.use_count() << std::endl;
    }

    std::cout << "The counts of shared pointer is: " << ptr_1.use_count() << std::endl;

    base_lists.push_back(ptr_1);

    std::cout << "The counts of shared pointer is: " << ptr_1.use_count() << std::endl;

    base_lists.clear();

    std::cout << "The counts of shared pointer is: " << ptr_1.use_count() << std::endl;

    std::cout << std::endl;
    std::cout << "// =============================================================" << std::endl;
    std::cout << "Testing DerivedWithNew..." << std::endl;
    std::cout << "// =============================================================" << std::endl;
    std::cout << std::endl;

    auto test_b = [&]() -> void {
        auto ptr_3 = make_shared<DerivedWithNew>();

        {
            auto ptr_4 = ptr_3;
            std::cout << "The counts of shared pointer is: " << ptr_3.use_count() << std::endl;
        }

        std::cout << "The counts of shared pointer is: " << ptr_3.use_count() << std::endl;

        base_lists.push_back(ptr_3);

        std::cout << "The counts of shared pointer is: " << ptr_3.use_count() << std::endl;

        base_lists.clear();

        std::cout << "The counts of shared pointer is: " << ptr_3.use_count() << std::endl;
    };

    test_b();

    std::cout << std::endl;
    std::cout << "Test ending..." << std::endl;

    return 0;
}