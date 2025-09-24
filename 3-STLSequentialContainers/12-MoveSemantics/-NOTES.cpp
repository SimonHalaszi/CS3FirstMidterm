#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * move semantics and std::move

    Deep copies happen in containers
        - When re-allocated/enlarged
        - xvalues(when returned), or prvalues(when temporary object is created)
        - when intialized in certain situations
    A copy constructor is ineffcient for large containers, and also not
    needed in some cases.

    In cases where copy constructor is not needed, say, you want
    to move the container from one place to another define move
    semantics and use std::move.

    Use rvalue reference instead of lvalue reference

    Define move-constructor and move-assignment
        MovableClass(MovableClass&& src) noexcept; // Move Constructor
        MovableClass& operator=(MovableClass&& src) noexcept; // Move Assignment

    The semantics is to use the original rather than create a copy.
    The original should be left in a "legal but undefined" state

    std::move()
        - Converts an lvalue to an xvalue (makes the object temporary)
            result = std::move(objToMove);
            MovableClass newObj(std::move(objToMove));
            myVector.push_back(std::move(objToMove));
            myVector.insert(it, std::move(objToMove));
    
        - std::move() can be applied to entire containers
            vector<int> v, v2 = {1, 2, 3, 4};
            v = std::move(v2);

        Note: Most likely no elements are moved, jsut pointers to buffers
        inside of v2 to v and older values of v are destroyed.
        delete [] array is O(n) operation.

    What does std::move actually do?

    std::move(input) signifies that the input value of any type
    is an xvalue and it also returns the rvalue reference to this 
    value. A returned rvalue reference is also considered a xvalue.

    But std::move does not do the moving. Its supposed to be used
    in the context of moving. Say you standalone call std::move(input)
    If input was an lvalue it will still exist in the same state as it
    was. But std::move will return an xvalue, rvalue reference to the input.

    However, calling a standalone std::move(input) is bad style. And
    calling std::move just to get an rvalue reference is also bad style.
    It is to be used in only a moving context, that is, assignment and
    moving of an lvalue, or any value, that will not need to be used
    after the call of std::move.

    Compiler will implicitly use move semantics on rvalues. So no need
    to std::move and object that gets returned unless that return was
    a reference to an lvalue or pointer.

    Also worth noting not every type has move semantics. Int for example
    will just not 'move' it will just allocate a whole new space in memory
    for the int you are assigning to. So this is why knowing that std::move
    doesnt move anything is important. Its up to the design of the value
    type to actually move things. so int i = std::move(lvalueInt) will
    actually leave lvalueInt completely usable and wont even move it into i

    Note: Compiler would automatically use move semantics for rvalues
          if semantics are defined.

    // ---------------------------------------------------- */
}


