/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* shallow vs. deep copy

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

    std::cout << "Deep copying objOne into objTwo..." << std::endl;
    MyClass objTwo(objOne);
    std::cout << "objTwo: "; objTwo.print(); std::cout << std::endl;

    std::cout << "Changing objTwo..." << std::endl;
    objTwo.assignAll(30);
    std::cout << "objOne: "; objOne.print(); std::cout << std::endl;
    std::cout << "objTwo: "; objTwo.print(); std::cout << std::endl;

    std::cout << "Shallow copying objOne into objThree..." << std::endl;
    MyClass objThree(objOne, 0);
    std::cout << "objThree: "; objThree.print(); std::cout << std::endl;

    std::cout << "Changing objThree..." << std::endl;
    objThree.assignAll(50);
    std::cout << "objOne: "; objOne.print(); std::cout << std::endl;
    std::cout << "objThree: "; objThree.print(); std::cout << std::endl;
    std::cout << "Uh oh objThree changed objOne. Dynamic classes need deep copies. " << std::endl;

    std::cout << "Deep assigning objOne into objTwo..." << std::endl;
    objTwo = objOne;
    std::cout << "objTwo: "; objTwo.print(); std::cout << std::endl;

    std::cout << "Changing objTwo..." << std::endl;
    objTwo.assignAll(30);
    std::cout << "objOne: "; objOne.print(); std::cout << std::endl;
    std::cout << "objTwo: "; objTwo.print(); std::cout << std::endl;

    std::cout << "Shallow assigning objOne into objTwo..." << std::endl;
    objTwo.shallowAssign(objOne);
    std::cout << "objTwo: "; objTwo.print(); std::cout << std::endl; 

    std::cout << "Changing objTwo..." << std::endl;
    objTwo.assignAll(100);
    std::cout << "objOne: "; objOne.print(); std::cout << std::endl;
    std::cout << "objTwo: "; objTwo.print(); std::cout << std::endl;
    std::cout << "objThree: "; objThree.print(); std::cout << std::endl;

    std::cout << "Uh oh objTwo changed objOne and objThree. Dynamic classes need deep assigns. " << std::endl;

    std::cout << "Shallow assigning objOne into objTwo..." << std::endl;
    objTwo.shallowAssign(objOne);
    std::cout << "objTwo: "; objTwo.print(); std::cout << std::endl; 

    std::cout << "What is this junk data?" << std::endl;
    std::cout << "shallowAssign deletes the dynamic memory only if this != &rhs. " 
    << "Which is true here. But they share the same pointer. BAD." << std::endl;

    std::cout << "Destructor is commented out, why? " << std::endl;
    std::cout << "Since we did bad shallow copies and assigns the destructor will try double free memory. BAD. " << std::endl;

}