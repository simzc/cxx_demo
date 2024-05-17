#include <iostream>

/// @struct Circle
/// @brief Functor to calculate the area of circle
struct Circle {
    explicit Circle(const double& radius) : m_radius(radius){};

    void operator()() const { std::cout << "Circle area is: " << 3.1415926 * m_radius * m_radius << std::endl; };

    double m_radius;
};

/// @struct Square
/// @brief Functor to calculate the area of square
struct Square {
    explicit Square(const double& length) : m_length(length){};

    void operator()() const { std::cout << "Square area is: " << m_length * m_length << std::endl; };

    double m_length;
};

int main(int argc, const char** argv) {
    Circle(0.2)();
    Square(0.2)();

    return 0;
}