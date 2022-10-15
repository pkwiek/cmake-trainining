#include <iostream>

class ExampleInterface
{
    virtual void method() = 0;
};

int main()
{
    std::cout << "Hello ccache example!" << std::endl;
}