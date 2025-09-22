#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * emplace()
    
    emplace() - Allocates a place in the container and incokes
    the constructor with specified arguments on it
        MovableClass(int i, int j); // constructor
        std::vector<MovableClass<int>> v;
        v.emplace_back(5, 10); // invokes constructor on new element at back

    - Advantages over move semantics
        - Saves resources even over move semantics in case object
        is not an lvalue. [ doesnt exist before hand ]
        - Greater variety of constructors, not just move constructor for
        insertion.

    Matching emplace() function exist for almost all functions and all
    containers with a matching push and insert(). fill insert
    and range insert however dont have emplace equivalant. emplace() is
    for single object creation.
        MovableClass(int i, int j); // constructor
        std::deque<MovableClass<int>> d;
        d.emplace_back(5, 10); // invokes constructor on new element at back
        d.emplace(d.begin(), 1, 2);



    // ---------------------------------------------------- */
}


