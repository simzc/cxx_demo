#include <iostream>

int main(int argc, const char** argv) {
    #if __cplusplus >= 201703L
        
    std::cout << "cxx_std is: " << __cplusplus << std::endl;   
    #endif // end if __cplusplus 
    return 0;
}