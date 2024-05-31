#include <iostream>

#if __linux__
    #include <experimental/source_location>
#else
    #include <source_location>
#endif

int main(int argc, const char** argv) {
    // Location info
    #if __linux__
        const std::experimental::source_location& location = std::experimental::source_location::current();
    #else
        const std::source_location& location = std::source_location::current();
    #endif
    

    // clang-format off
    std::cout << "Information of current location: "        << std::endl
              << "Column: "    << location.column()         << std::endl
              << "Function: "  << location.function_name()  << std::endl
              << "File: "      << location.file_name()      << std::endl
              << std::endl;
    // clang-format on

    return 0;
}