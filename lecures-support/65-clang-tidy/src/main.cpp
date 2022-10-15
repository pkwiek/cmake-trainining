#include <iostream>

class ExampleInterface
{
    virtual ~ExampleInterface() = default;
    virtual void method() = 0;
};

int main()
{
    std::cout << "Hello clang-tidy example!" << std::endl;
}