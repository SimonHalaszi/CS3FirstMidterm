/*
STL SEQUENTIAL CONTAINERS

* rvalue reference vs. lvalue reference, reference overload

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <string>
#include <iostream>

void func(int& i) {     // Pass by reference
    std::cout << "overloaded with lvalue ref " << i << std::endl;
}

void func(int&& i) {    // Pass by rvalue reference
    std::cout << "overloaded with rvalue ref " << i << std::endl;
}

int main() {

    // i is lvalue
    int i = 10;

    // lvalue reference
    // lvalue reference binds to lvalue (xvalue or lvalue)
    // Can be treated as alias for lvalue
    // Useful as passing paradigm
    int& lvalueRef = i;

    // rvalue reference
    // rvalue reference binds to rvalue (xvalue or prvalue)
    // Can be treated as life time extender of this rvalue
    // Useful for move semantics
    // 5 + 5 is rvalue
    int&& rvalueRef = 5 + 5;

    // Compiler can overload functions based of the difference
    // lvalue calls
    func(i);
    func(lvalueRef);

    // Even though rvalueRef is binded to rvalue it itself is not
    // an rvalue as rvalueRef has a given identity and value
    func(rvalueRef);
   
    // rvalue call
    func(5+5);

    // This overloaded by this distinction is used for
    // copy constructor/assignment vs move constructor/assignment

    // What is std::move(input)?

    /*
    
    A bit confusing as std::move doesnt actually "move" anything
    but more like is a signifier for moving things.

    std::move(input) can take an input of any value type. And it
    will signify this input as an xvalue. If this input is an
    lvalue it will still be an lvalue, it will still have an identifier,
    its space in memory, and its state. 
    But...
    std::move(input) is used in the context where input will be moved.
    So input will be changed by the context it was used in but all
    std::move actually does is return the rvalue reference to a value.
    The returned rvalue is also considered an xvalue not a prvalue.

    For primitive types like integer the semantics for moving isnt
    invasive in anyway shape or form so the inputted lvalue will
    actually still be fully usable after being passed into std::move.

    But for say a class that has move semantics implemented this will
    be invasive. Input lvalue will be left in a safe but undefined state
    and inputted lvalue should not be used after function call.
    
    */

    // Nothing actually happens to i. Just an rvalue reference to it was
    // returned. This rvalue return is an xvalue, but i isnt actually an
    // xvalue it was more just signified to be one. [ In an improper context ]

    // The actual moving of i will be discussed later in 12-MoveSemantics
    std::cout << std::move(i);
}
