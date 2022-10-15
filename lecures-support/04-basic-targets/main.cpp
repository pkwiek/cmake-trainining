#include <iostream>

#include "ExampleClass.h"

int main() {

    const auto object = ExampleClass();

    std::cout << "Hello " << object.getName() << "!" << std::endl;
    return 0;
}
