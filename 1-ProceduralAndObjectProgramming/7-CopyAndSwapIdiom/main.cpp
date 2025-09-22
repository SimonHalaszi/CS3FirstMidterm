/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* copy-and-swap idiom

c++ main.cpp MyClass.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include "MyClass.hpp"

int main() {

    MyClass objOne(10);
    objOne.assignAll(10);
    std::cout << "objOne: "; objOne.print(); std::cout << std::endl;

    MyClass objTwo(10);
    objTwo.assignAll(40);
    std::cout << "objTwo: "; objTwo.print(); std::cout << std::endl;

    std::cout << "Assigning objTwo into objOne using copy-and-swap idiom" << std::endl;
    objOne = objTwo;
    std::cout << "objOne: "; objOne.print(); std::cout << std::endl;
    std::cout << "objTwo: "; objTwo.print(); std::cout << std::endl;

    std::cout << "Changing objTwo..." << std::endl;
    objTwo.assignAll(70);
    std::cout << "objOne: "; objOne.print(); std::cout << std::endl;
    std::cout << "objTwo: "; objTwo.print(); std::cout << std::endl;

    std::cout << "Deep copy made with copy-and-swap idiom. Because overload assignment takes right operand by value" << std::endl;
}