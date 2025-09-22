/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* range-based for and pass-by value, reference and const reference loop variable

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;
    
    // Typical for loop
    for(int i = 0; i < 5; ++i) {
        v.push_back((i+1) * 10);
    }
    
    // Range-based for const pass-by reference loop variable
    std::cout << "Range based for with const pass-by reference. Printing all elements in v: " << std::endl;
    for(const auto& element : v) {
        std::cout << element << " ";
    }
    std::cout << std::endl << std::endl;

    // Range-based for pass-by value
    std::cout << "Range based for with pass-by value. Adding 10 to each element of v's using copy: " << std::endl;
    for(auto element : v) {
        element += 10;
        std::cout << element << " ";
    }
    std::cout << std::endl << std::endl;

    // Range-based for const pass-by reference loop variable
    std::cout << "Range based for with const pass-by reference. Printing all elements in v. Unchanged: " << std::endl;
    for(const auto& element : v) {
        std::cout << element << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Range-based for pass-by reference
    std::cout << "Range based for with pass-by reference. Adding 10 to each element of v's using reference: " << std::endl;
    for(auto& element : v) {
        element += 10;
        std::cout << element << " ";
    }
    std::cout << std::endl << std::endl;  

    // Range-based for const pass-by reference loop variable
    std::cout << "Range based for with const pass-by reference. Printing all elements in v. Changed: " << std::endl;
    for(const auto& element : v) {
        std::cout << element << " ";
    }
    std::cout << std::endl << std::endl;
}