#include <iostream>

class Base {
  public:
    virtual ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
  public:
    ~Derived() override {  // 使用override关键字
        std::cout << "Derived destructor" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    delete b;  // 正确调用Derived和Base的析构函数
    return 0;
}
