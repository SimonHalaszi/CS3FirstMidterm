#include <iostream>

int main() {
    

    /* ---------------------------------------------------- //

    Can have a nontype parameter to a template!

    Non-type template parameters (NTPs) in C++ are template parameters that represent 
    values rather than types. They allow templates to be parameterized by compile-time 
    constants, enabling more flexible and powerful generic programming.

    Can be of any specific type/class

    template<typename T, int size>
    class Stack{
        private:
            T items_[size];
            int tos_;    
    };

    Treated as 

    Initalized at instantiation

    Stack<char, 10> charStack;

    // ---------------------------------------------------- */
}



