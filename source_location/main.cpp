#include <iostream>
#include <source_location>

int main(int argc, const char** argv) {
    // Location info
    const std::source_location& location = std::source_location::current();

    // clang-format off
    std::cout << "Information of current location: "        << std::endl
              << "Column: "    << location.column()         << std::endl
              << "Function: "  << location.function_name()  << std::endl
              << "File: "      << location.file_name()      << std::endl
              << std::endl;
    // clang-format on

    return 0;
}