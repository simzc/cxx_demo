#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <cmath>

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
    /// @brief Int type
    /// @param i Input value
    void operator()(int i) const { std::cout << "int value: " << i << std::endl; }

    /// @brief Double type
    /// @param i Input value
    void operator()(double i) const { std::cout << "double value: " << i << std::endl; }

    /// @brief String type
    /// @param i Input value
    void operator()(std::string i) const { std::cout << "string value: " << i << std::endl; }
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
    var_void vis_int = 0;
    var_void vis_double = 0.0;
    var_void vis_string = "hello world!";

    std::visit(Visitor_void(), vis_int);
    std::visit(Visitor_void(), vis_double);
    std::visit(Visitor_void(), vis_string);

    // ###############################################################################
    //  Case 2: user-defined return type
    var_type vis_circle = Circle(0.2);
    var_type vis_square = Square(0.2);

    std::cout << "Circle area is: " << std::visit(Visitor_type(), vis_circle) << std::endl;
    std::cout << "Square area is: " << std::visit(Visitor_type(), vis_square) << std::endl;

    return 0;
}