#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <cmath>
#include <type_traits>

struct Circle;
struct Square;

// Alias the variant value
using var_void = std::variant<int, double, std::string>;
using var_type = std::variant<Circle, Square>;

/// @struct Circle
/// @brief Functor to calculate the area of circle
struct Circle {
    Circle(const double& radius) : m_radius(radius) {}

    double m_radius;
};

/// @struct Square
/// @brief Functor to calculate the area of square
struct Square {
    Square(const double& length) : m_length(length) {}

    double m_length;
};

/// @struct Visitor with void return type
/// @brief Fuctor for std::visitor
struct Visitor_void {
#if 0
    
    /// @brief Int type
    /// @param i Input value
    void operator()(int i) const { std::cout << "int value: " << i << std::endl; }

    /// @brief Double type
    /// @param i Input value
    void operator()(double i) const { std::cout << "double value: " << i << std::endl; }

    /// @brief String type
    /// @param i Input value
    void operator()(std::string i) const { std::cout << "string value: " << i << std::endl; }

    // Approach for C++20 
    void operator()(auto&& args) const {
        std::cout << "Args :" << args << std::endl;

        // Remove the reference property
        using type = std::decay_t<decltype(args)>;
        
        // Int type
        if constexpr (std::is_same_v<type, int>) {
            std::cout << "Int type: " << args << std::endl;
        }

        // Double type
        if constexpr (std::is_same_v<type, double>) {
            std::cout << "Double type: " << args << std::endl;
        }

        // String type
        if constexpr (std::is_same_v<type, std::string>) {
            std::cout << "String type: " << args << std::endl;
        }
    }
#endif  // end if macro

    // Approach for C++17
    template <typename Type>
    void operator()(Type&& args) const {
        std::cout << "Args :" << args << std::endl;

        // Remove the reference property
        using type = std::decay_t<Type>;

        // Int type
        if constexpr (std::is_same_v<type, int>) {
            std::cout << "Int type: " << args << std::endl;
        }
        // Double type
        else if constexpr (std::is_same_v<type, double>) {
            std::cout << "Double type: " << args << std::endl;
        }
        // String type
        else if constexpr (std::is_same_v<type, std::string>) {
            std::cout << "String type: " << args << std::endl;
        }
    }
};

/// @struct Visitor with area return type
/// @brief Fuctor for std::visitor
struct Visitor_type {
    /// @brief Calculate the area of circle
    /// @param circle Circle object
    /// @return Area of circle
    double operator()(const Circle& circle) const { return 3.1415926 * std::pow(circle.m_radius, 2); }

    /// @brief Calculate the area of square
    /// @param circle Square object
    /// @return Area of square
    double operator()(const Square& square) const { return square.m_length * square.m_length; }
};

int main(int argc, const char** argv) {
    // ###############################################################################
    //  Case 1: void return type
    std::cout << "// #################################################" << std::endl;
    std::cout << "Case 1: void return type." << std::endl;
    var_void vis_int = 0;
    var_void vis_double = 1.0;
    var_void vis_string = "hello world!";

    std::visit(Visitor_void(), vis_int);
    std::visit(Visitor_void(), vis_double);
    std::visit(Visitor_void(), vis_string);

    std::cout << std::endl;

    // ###############################################################################
    //  Case 2: user-defined return type
    std::cout << "// #################################################" << std::endl;
    std::cout << "Case 2: user-defined return type." << std::endl;
    var_type vis_circle = Circle(0.2);
    var_type vis_square = Square(0.2);

    std::cout << "Circle area is: " << std::visit(Visitor_type(), vis_circle) << std::endl;
    std::cout << "Square area is: " << std::visit(Visitor_type(), vis_square) << std::endl;

    std::cout << std::endl;

    // ###############################################################################
    //  Case 3: std::vector<std::variant<Type>>
    std::cout << "// #################################################" << std::endl;
    std::cout << "Case 3: std::vector<std::variant<Type>>." << std::endl;
    std::vector<var_void> vector = {0, 1.0, "hello world!"};
    for (auto&& vec : vector) {
        std::visit(
            [](auto&& args) {
                using type = std::decay_t<decltype(args)>;
                // Int type
                if constexpr (std::is_same_v<type, int>) {
                    std::cout << "Int type: " << args << std::endl;
                }
                // Double type
                else if constexpr (std::is_same_v<type, double>) {
                    std::cout << "Double type: " << args << std::endl;
                }
                // String type
                else if constexpr (std::is_same_v<type, std::string>) {
                    std::cout << "String type: " << args << std::endl;
                }
            },
            vec);
    }

    return 0;
}