#include <iostream>
#include <typeinfo>
#include <vector>

/// @brief Forward declaration
class V_class {};
struct V_struct {};
void v_func() {}

/// @brief Print the name of typeinfo
/// @tparam Type Type of argument
/// @param val Input value
/// @return Type info
template <typename Type>
const char* PrintTypeInfo(Type val) {
    return typeid(val).name();
}

int main() {
    // Integral type
    {
        char v(0);
        std::cout << "The type of char is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        short v(0);
        std::cout << "The type of short is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        int v(0);
        std::cout << "The type of int is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        long v(0);
        std::cout << "The type of long is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        long long v(0);
        std::cout << "The type of long long is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    std::cout << std::endl;

    {
        int8_t v(0);
        std::cout << "The type of int8_t is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        int16_t v(0);
        std::cout << "The type of int16_t is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        int32_t v(0);
        std::cout << "The type of int32_t is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        int64_t v(0);
        std::cout << "The type of int64_t is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    std::cout << std::endl;

    // Positive integral type
    {
        unsigned char v(0);
        std::cout << "The type of unsigned char is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        unsigned short v(0);
        std::cout << "The type of unsigned short is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        unsigned int v(0);
        std::cout << "The type of unsigned int is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        unsigned long v(0);
        std::cout << "The type of unsigned long is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        unsigned long long v(0);
        std::cout << "The type of unsigned long long is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    std::cout << std::endl;

    {
        uint8_t v(0);
        std::cout << "The type of uint8_t is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        uint16_t v(0);
        std::cout << "The type of uint16_t is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        uint32_t v(0);
        std::cout << "The type of uint32_t is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        uint64_t v(0);
        std::cout << "The type of uint64_t is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    std::cout << std::endl;

    // Floating type
    {
        float v(0);
        std::cout << "The type of float is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        double v(0);
        std::cout << "The type of double is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    std::cout << std::endl;

    // Array type
    {
        char v[] = {0};
        std::cout << "The type of char[] is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        short v[] = {0, 0};
        std::cout << "The type of short[] is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        int v[] = {0, 0, 0};
        std::cout << "The type of int[] is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        long v[] = {0, 0, 0, 0};
        std::cout << "The type of long[] is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        long long v[100] = {0};
        std::cout << "The type of long long[] is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        float v[] = {0.0f, 0.0f};
        std::cout << "The type of float[] is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        double v[] = {0.0, 0.0};
        std::cout << "The type of double[] is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    // Container type
    {
        std::vector<int> v(20, 1);
        std::cout << "The type of std::vector<int> is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        std::vector<double> v(20, 1);
        std::cout << "The type of std::vector<double> is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    // String type
    {
        std::string v("hello");
        std::cout << "The type of std::string is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    std::cout << std::endl;

    // Pointer type
    {
        int* v;
        std::cout << "The type of int* is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        double* v;
        std::cout << "The type of double* is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        double** v;
        std::cout << "The type of double** is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        // Array of pointer
        double* v[3];
        std::cout << "The type of array of pointer is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        // Pointer to array
        double(*v)[3];
        std::cout << "The type of pointer to array is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        std::string* v;
        std::cout << "The type of pointer to std::string is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        std::vector<double>* v;
        std::cout << "The type of std::vector<double>* is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    {
        std::vector<std::string>* v;
        std::cout << "The type of std::vector<std::string>* is indicated as:\t" << PrintTypeInfo(v) << std::endl;
    }

    std::cout << std::endl;

    // Struct type
    { std::cout << "The type of struct is indicated as:\t" << typeid(V_struct).name() << std::endl; }

    // Struct object
    {
        V_struct v_struct;
        std::cout << "The type of struct object is indicated as:\t" << PrintTypeInfo(v_struct) << std::endl;
    }

    // Class type
    { std::cout << "The type of class is indicated as:\t" << typeid(V_class).name() << std::endl; }

    // Class object
    {
        V_class v_class;
        std::cout << "The type of class object is indicated as:\t" << PrintTypeInfo(v_class) << std::endl;
    }

    // Function type
    { std::cout << "The type of function is indicated as:\t" << typeid(v_func).name() << std::endl; }

    return 0;
}
