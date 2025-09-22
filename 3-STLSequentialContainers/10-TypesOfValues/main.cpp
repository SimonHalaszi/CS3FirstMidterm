/*
STL SEQUENTIAL CONTAINERS

* lvalue, xvalue, glvalue, rvalue, pravlue

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <string>
#include <iostream>

int& func(int& b) {
    return b;
}

int main() {
    // More notes based

    /*

    glvalue - General lvalue, either lvalue or xvalue

    lvalue - Named because it appears on left side of assignment.
    lvalue is a value that has an identifier or if an expression
    results in a reference to a permanant space in memory that is 
    an lvalue. Think pointer dereference and returning an address.

    rvalue - Right value, either prvalue or xvalue

    prvalue - An rvalue that is not an xvalue. The result
    of any expression that doesnt refer to one, any permanant spot in
    memory or two, an rvalue reference.    

    xvalue - Refers to any lvalue that has signified express
    permission to be moved, or an lvalue near the end of its life.
    Also if an expression results in an rvalue reference that is
    an xvalue. std::move(input) produces an xvalue and also
    signifys input as an xvalue. If input was an lvalue
    still falls under lvalue but it has been signified as moved
    or expired. And the result of std::move(input) is an rvalue.
    
    */

    // str is an lvalue | std::string("bob") + "rob" is a prvalue
    std::string str = (std::string("bob") + "rob");

    // str2 is an lvalue | the result of std::move(str) is an xvalue and str is now an xvalue (but still an lvalue)
    std::string str2 = std::move(str);
    // The term xvalue also refers to lvalues that have been signified as moved or expired. So str is both lvalue and xvalue

    // i is an lvalue | 29 + 32 is a prvalue
    int i = 10 + 10;

    // i is an lvalue | func(i) returns an lvalue | func(i) + 10 is a prvalue
    i = func(i) + 10;

    std::cout << i << std::endl;

    // ptr is an lvalue | &i is an prvalue ( &i gets calculated into a memory address )
    int* ptr = &i;

    // *ptr is an lvalue ( refers to permanant spot in memory )
    std::cout << *ptr << std::endl;

}