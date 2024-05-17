#include <string>
#include <utility>
#include <iostream>

/// @brief Unique pointer manager for Type of object
/// @tparam Type Type of object
template <typename Type>
class UniquePtr {
  public:
    /// @brief Default constructor
    UniquePtr() : m_ptr(nullptr) { std::cout << "Default constructor invoked." << std::endl; }

    /// @brief Constructor with initial pointer
    explicit UniquePtr(Type* ptr) : m_ptr(ptr) { std::cout << "Constructor invoked." << std::endl; }

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

    /// @brief Get the pointer of object
    Type* Get() const { return m_ptr; }

    /// @brief Reload operator of ->
    Type*& operator->() { return m_ptr; }

    /// @brief Reload operator of ->
    Type* operator->() const { return m_ptr; }

    /// @brief Reload operator of *
    Type& operator*() { return *m_ptr; }

  private:
    Type* m_ptr;
};

/// @class
/// @brief
class Any {
  public:
    /// @brief
    /// @tparam Type
    /// @param val
    template <typename Type>
    explicit Any(Type val) : m_value(new ValueHolder<Type>(val)) {}

    /// @brief Copy constructor
    Any(const Any& src) { *this = src; }

    /// @brief Assignment operator
    Any& operator=(const Any& src) {
        this->m_value = src.m_value->Clone();
        return *this;
    }

    /// @brief Destructor
    ~Any() = default;

    template <typename Type>
    Type& GetValue() const {
        if (auto ptr = dynamic_cast<ValueHolder<Type>*>(m_value.Get())) {
            return ptr->m_data;
        }
        throw std::logic_error("Type error!");
    }

  private:
    /// @brief Abstract value
    struct Value {
        virtual ~Value() {}
        virtual UniquePtr<Value> Clone() = 0;
    };

    /// @brief Concrete object holder
    /// @tparam Type
    template <typename Type>
    struct ValueHolder : public Value {
        /// @brief Constructor
        /// @param data Initial value
        explicit ValueHolder(Type data) : m_data(data) {}

        /// @brief Clone function
        /// @return Covariant type
        UniquePtr<Value> Clone() override { return new ValueHolder<Type>(m_data); }

        /// @brief  Destructor
        ~ValueHolder() override = default;

        Type m_data;
    };

    UniquePtr<Value> m_value;
};

int main(int argc, const char** argv) {
    Any any = 1;

    try {
        auto value_int = any.GetValue<int>();
        std::cout << "value_int: " << value_int << std::endl;

        any = "abc";
        auto value_chars = any.GetValue<const char*>();
        std::cout << "value_chars: " << value_chars << std::endl;
    } catch (...) {
    }
    return 0;
}