#include <iostream>

int main() {
    
    // * rvalue references, scopes for r-value references, function returning rvalues

    // ---------------------------------------------------- //
    
    // rvalue reference && can "bind" to rvalue

    int j = 2;
    int&& k = j + 5;

    // compiler resolves the overloads

    void func(int&);
    void func(int&&);

    func(j); // pass by reference
    func(55); // pass by rvalue reference

    // ---------------------------------------------------- //

    // Move Semantics

    /*
    
    When we move a dynamically allocated object into a container a deep
    copy is called. Also deep copies are called when containers need
    re-allocated/enlarged. Also when containers return by value said
    object (prvalue). And when the container is intialized in specific 
    scenarios.

    None of this is good. Copy constructor being called for a deep copy
    can be avoided using move semantics on objects we wont longer need.

    Make constructor and assignment using rvalue reference. These
    are the move constructor and move assignment.

    The semantics is to use the orginal rather than create copy.
    The original should be left in a "legal but undefined" state.

    Instead of deep copying all dynamically allocated memory just
    assign and reassign pointers and values. o(1) operation instead
    of some higher complexity!
    
    */

    class MyClass{
        // Move Constructor
        MyClass(MyClass&& moveMe);
        // Move Assignment
        MyClass& operator=(MyClass&& moveMe);
    };

    /* ---------------------------------------------------- //
    
    std::move()

    Converts an lvalue to an xvalue (signifys object to moved and as expired)
    
    More specifcally takes the inputted variable and returns the
    rvalue reference to it.

    Returning of an rvalue reference is am xvalue

    std::move() can be applied to any variable. But move
    semantics in themselves can vary from type to type.

    // ---------------------------------------------------- */
}



