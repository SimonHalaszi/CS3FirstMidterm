/*
TEMPLATES

* standalone function templates, type parameter deduction

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <string>

// Nothing useful just to show how this works
template<typename T>
T standaloneTemplate(const T& var);

int main() {
    int a = 1230;
    // Type deduced to integer at compile time
    // The process of the compiler figuring out T's type through argument is deduction.
    std::cout << standaloneTemplate(a) << std::endl;

    /*

    Instantiation of standaloneTemplate used for this will be this
    
    int standaloneTemplate(const int& var) {
        return var;
    }
    
    Instantiation is the real code that is executed by filling in T with deduced type.
    The deduction happens at compile time and is based on argument.

    */

    // To show standaloneTemplate works for any type (provided type supports copying/assignment)
    double b = 1230.30;
    std::cout << standaloneTemplate(b) << std::endl;   

    std::string c = "Hello, World!";
    std::cout << standaloneTemplate(c) << std::endl;  
}

template<typename T>
T standaloneTemplate(const T& var) {
    return var;
}