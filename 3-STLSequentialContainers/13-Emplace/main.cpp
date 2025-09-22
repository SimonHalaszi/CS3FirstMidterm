/*
STL SEQUENTIAL CONTAINERS

* emplace()

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <deque>
#include "MyClass.hpp"
#include <iostream>

int main() {
    /*
    
    Can use emplace to construct an object exactly where
    object is getting inserted or pushed. Where there is a 
    push or insert function there is an emplace equivalant

    See 9-ContainerUpdateFunctions for insert and push specifics

    */

    std::deque<MyClass<int>> d;
    // Calls the constuctor given a size of MyClass
    d.emplace_front(10);
    // Calls default constructor of MyClass
    d.emplace_front();

    std::deque<MyClass<int>>::iterator it = d.begin();

    // No fill insert
    // d.emplace(it, 2, 10);
    d.emplace(it, 10);


    // No range insert
    // std::vector<MyClass<int>> v;
    // v.emplace(v.begin(), q.begin(), q.end());

    // Emplace is used for single object intialization

    for(const auto& e : d) {
        std::cout << e.size() << " "; // 10 0 10
    }

    /*
    
    Advantages over moving?

    Saves resources even over move semantics in case object is not
    an lvalue. [ doesnt exist before hand ]
    Greater variety of constructors for inserting. Not just move constructor.
    
    */
}
