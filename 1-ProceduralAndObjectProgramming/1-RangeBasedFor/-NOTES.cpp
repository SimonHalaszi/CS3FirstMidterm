#include <iostream>
int main() {
    
    // ---------------------------------------------------- //

    // * range-based for and pass-by value, reference and const reference loop variable

    // auto - Type to be determined by compiler (C++11)

    auto i = 7.0; // Nice for type of loop variables

    // could also use an 'auto&' and 'const auto'

    // decltype(expr) - type is same as expr (C++11)

    decltype(i) j = 8;   

    // ---------------------------------------------------- //
    // A range-based-for (C++11) is as follows

    // Read as for every element in a
    int a[] = {10, 20, 30, 40};
    for(int element : a) {
        std::cout << element;
    }

    // Can use auto for nice looping
    for(auto element : a) {
        std::cout << element;
    }

    // Examples for pass-by value, pass-by reference and const pass-by reference
    
    // pass-by value
    for(auto element : a) {
        std::cout << element;
    }
    // pass-by reference
    for(auto& element : a) {
        std::cout << element;
    }
    // const pass-by reference
    for(const auto& element : a) {
        std::cout << element;
    }

    // ---------------------------------------------------- //

}


