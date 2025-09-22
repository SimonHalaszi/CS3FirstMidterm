#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * rvalue reference vs. lvalue reference, reference overload

    - lvalue reference & can "bind" to lvalue
        int j = 5;          // 5
        int& refToJ = j;    // 5

    - rvalue reference && can "bind" to rvalue
        int&& k = j + 5;    // 10

    - Compiler resolves the overloads
        void func(int&);
        void func(int&&);

        func(j);    // pass by reference
        func(55);   // pass by rvalue reference

        This overload distinction is used for
        copy constructor/assignment vs. move constructor/assignment

    // ---------------------------------------------------- */
}


