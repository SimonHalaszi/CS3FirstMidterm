/*
STL SEQUENTIAL CONTAINERS

* move semantics and std::move

c++ main.cpp 
./a.out > output.txt
rm ./a.out

*/

#include <deque>
#include "MyClass.hpp"
#include <iostream>

MyClass<int> makeObj() {
    MyClass<int> obj(70);
    for(int i = 0; i < obj.size(); ++i) {
        obj.array()[i] = i;
    }
    return obj;    
}

int main() {
    MyClass<int> obj(70);
    for(int i = 0; i < obj.size(); ++i) {
        obj.array()[i] = i;
    }

    std::deque<MyClass<int>> q;

    // If we didnt have move semantics

    // Uses a copy constructor. Thats expensive my obj is pretty big!
    q.push_back(obj);

    // Uses a copy constructor. Thats expensive my obj is pretty big!
    // Potentially uses copy constructor twice! To get obj from inside 
    // makeObj() returned!
    q.push_back(makeObj());

    // Uses copy assignment so expensive!
    MyClass<int> obj2;
    obj2 = makeObj();

    // How do we prevent prvalue or xvalue MyClass from copying?
    // We know we wont need it so how can we use the memory that
    // already exist good but is going to get deallocated?

    // Limiting scope to drive in point
    {
        // Will call move assignment! No remaking of makeObj
        MyClass<int> obj3;
        obj3 = std::move(makeObj());

        // Will use move constructor! We wont need obj3 anymore
        q.push_back(std::move(obj3));

        // Just to show that obj3 got moved...
        std::cout << obj3.size() << std::endl; // 0
    }

    // Uses move constructor!
    q.push_back(std::move(makeObj()));

    // Calling std::move on obj to show that all move does is return
    // an rvalue reference
    // obj is not moved! But std::move(obj) will signify in a proper
    // context a move operation.
    std::cout << std::move(obj).size() << std::endl; // 70
    std::cout << obj.size() << std::endl; // still 70

    /*
    
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

    Also worth noting not every type has move semantics. Int for example
    will just not 'move' it will just allocate a whole new space in memory
    for the int you are assigning to. So this is why knowing that std::move
    doesnt move anything is important. Its up to the design of the value
    type to actually move things. so int i = std::move(lvalueInt) will
    actually leave lvalueInt completely usable and wont even move it into i

    Note: Compiler would automatically use move semantics for prvalues
          if semantics are defined.
    
    */
}
