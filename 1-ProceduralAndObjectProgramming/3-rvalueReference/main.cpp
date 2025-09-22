/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* rvalue references, scopes for r-value references, function returning rvalues

c++ main.cpp MyClass.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <vector>
#include "MyClass.hpp"

int lvaluePassFunc(int&);
void rvaluePassFunc(int&&);

// You can overloaded functions based off this distinction

/*

See declarations and examples of BAD uses of rvalue references in functions
at the bottom of the file.

*/


int main() {
    /* ---------------------------------------------------- //
                    Procedural rvalue Reference
    // ---------------------------------------------------- */

    std::cout << "Procedural rvalue Reference" << std::endl << std::endl;

    int lvalueInt = 25;
    std::cout << "lvalueInt: " << lvalueInt << std::endl;

    // "Binds" to the rvalue of these expressions
    int&& rvalueRefOne = 2;
    std::cout << "rvalueRefOne to { 2 }: " << rvalueRefOne << std::endl;
    int&& rvalueRefTwo = lvalueInt/(3+2);
    std::cout << "rvalueRefTwo to { lvalueInt/3+2 }: " << rvalueRefTwo << std::endl;

    std::cout << "lvalueInt += 100 & rvalueRefTwo += 100" << std::endl;
    lvalueInt += 100;
    rvalueRefTwo += 100;

    std::cout << "lvalueInt: " << lvalueInt << std::endl;
    std::cout << "rvalueRefOne: " << rvalueRefOne << std::endl;
    std::cout << "rvalueRefTwo: " << rvalueRefTwo << std::endl;

    std::cout << std::endl;
    std::cout << "lvalue pass in realint: " << std::endl;
    lvaluePassFunc(lvalueInt);                // Normal reference
    
    std::cout << std::endl;
    std::cout << "rvalue pass in 100 + 54 + 30: " << std::endl;
    rvaluePassFunc(100 + 54 + 30);            // rvalue reference
    
    std::cout << std::endl;
    std::cout << "rvalue pass in func(lvalueInt) which passes in lvalue: " << std::endl;
    rvaluePassFunc(lvaluePassFunc(lvalueInt));          // func(j) returns r value which gets passed into rvalue func

    std::cout << std::endl;
    int&& rvalueRefThree = lvaluePassFunc(lvalueInt);
    std::cout << "caught last functions return rvalue with rvalueRefThree" << std::endl;
    std::cout << "last functions return rvalue now has the scope of rvalueRefThree" << std::endl;
    std::cout << "rvalueRefThree: " << rvalueRefThree << std::endl;
    
    // This next part really confused me so heres a BOOK!

    /*
    
    lvalueInt (lvalue) 
        ↓ std::move
    xvalue (rvalue reference to same object)
        ↓ usage context
        ├── int&& → binds to xvalue → same memory address
        └── int   → copies from xvalue → new memory with same value
    
    */

    /*
    
    So what does move actually do? std::move(input) will turn input from an lvalue into
    an rvalue reference of itself. It then returns this rvalue reference of input. It 
    does NOT move or manipulate anything itself.

    This explains why our lvalueInt and rvalueReflvalueInt will share the same memory.
    The move constructor and move assignment is only called outside the function when 
    you do something like this...

    MyClass MyClassObjTwo(std::move(MyClassObjOne));
    
    or...

    MyClass MyClassObjTwo = std::move(MyClassObjOne);

    An invasive move constructor and move assignment IS NOT defined for primitave types, such as int.
    So what happens here is rvalueReflvalueInt is just assigned to the rvalue version of
    lvalueInt that std::move returned. However nothing destructive and no moving actually
    happends to lvalueInt. So when we assign rvalueReflvalueInt to std::move(lvalueInt); 
    it will actually just bind to the same memory address of the rvalue reference std::move 
    produced! Which is actually just the same address as the normal lvalueInt! We can also 
    explain why assigning lvalueIntTwo to std::move(lvalueInt); causes no issues in the same 
    way. lvalueIntTwo will actually just get assigned to the value held be the rvalue reference 
    that std::move returned! And thats why they dont share a memory address. So semantically 
    rvalueReflvalueInt  will act the same reflvalueInt! And lvalueInt is free to carry on 
    because it never actually gets moved. But using lvalueInt after calling std::move on it 
    is of course bad style. Because any variable with more robust move semantics will not have 
    the same luxury as int.

    In short std::move is a bad function name. Its not named after what it returns or
    accomplishes. Its named after the context of which it is to be used. Which causes
    confusion.

    */

    // Case 1: Bind to rvalue reference (reference semantics)
    int&& rvalueReflvalueInt = std::move(lvalueInt);
    // Case 2: Assign to regular int (copy semantics) 
    int lvalueIntTwo;
    lvalueIntTwo = std::move(lvalueInt);
    // Normal reference
    int& reflvalueInt = lvalueInt;
    
    std::cout << std::endl;
    std::cout << "rvalueReflvalueInt: " << rvalueReflvalueInt << std::endl;
    std::cout << "reflvalueInt: " << reflvalueInt << std::endl;
    std::cout << "lvalueInt: " << lvalueInt << std::endl;
    std::cout << "lvalueIntTwo: " << lvalueIntTwo << std::endl;

    std::cout << "lvalueInt += 100 " << std::endl;
    lvalueInt += 100;

    /*
    
    lvalueInt, rvalueReflvalueInt, reflvalueInt all share the same memory address
    lvalueIntTwo does not. The assignment for lvalueIntTwo actually just assigns
    the value inside the address of the rvalue reference from std::move(lvalueInt);
    
    */
    
    std::cout << std::endl;
    std::cout << "rvalueReflvalueInt: " << rvalueReflvalueInt << std::endl;
    std::cout << "reflvalueInt: " << reflvalueInt << std::endl;
    std::cout << "lvalueInt: " << lvalueInt << std::endl;
    std::cout << "lvalueIntTwo: " << lvalueIntTwo << std::endl;
    std::cout << std::endl;
    
    /*
    
    However all of this is in bad style. 
    Realistically do not use lvalueInt after calling std::move on it

    */

    /* ---------------------------------------------------- //
            Object Move Constructor and Assignment
    // ---------------------------------------------------- */

    std::cout << "Object Move Constructor and Assignment" << std::endl << std::endl;

    std::vector<MyClass> myClassVector;

    MyClass MyClassOne(10);

    MyClassOne.assignAll(1);
    
    std::cout << "MyClassOne: " << std::endl;
    MyClassOne.print();
    std::cout << std::endl;

    // MyClassOne is small and we want to use it later so push_back with pass-by-value
    myClassVector.push_back(MyClassOne);

    std::cout << "Pushed copy of MyClassOne into myClassVector" << std::endl;

    // Limiting scope to show that MyClassTwo is xvalue
    // Move Constructor
    {
        MyClass MyClassTwo(50);
        
        MyClassTwo.assignAll(2);
        
        std::cout << "MyClassTwo: " << std::endl;
        MyClassTwo.print();
        std::cout << std::endl;
        
        // MyClassTwo getting moved to vector is INITIALIZED using rvalue reference
        // Move Constructor called
        myClassVector.push_back(std::move(MyClassTwo));

        std::cout << "Moved MyClassTwo into myClassVector" << std::endl;
    }


    std::cout << "myClassVector contents: " << std::endl;
    for(const auto& element : myClassVector) {
        element.print();
        std::cout << std::endl;
    }

    MyClass MyClassThree;

    std::cout << "MyClassThree: " << std::endl;
    MyClassThree.print();
    std::cout << std::endl;


    // Limiting scope to show that MyClassFour is xvalue
    // Move Assignment
    {
        MyClass MyClassFour(50);

        MyClassFour.assignAll(4);

        std::cout << "MyClassFour: " << std::endl;
        MyClassFour.print();
        std::cout << std::endl;

        // MyClassThree getting ASSIGNED with rvalue reference
        // Moving MyClassFour into MyClassThree. Move Assignment.
        MyClassThree = std::move(MyClassFour);

        std::cout << "Moved MyClassFour into MyClassThree" << std::endl;
    }

    std::cout << "MyClassThree: " << std::endl;
    MyClassThree.print();
    std::cout << std::endl;

}

int lvaluePassFunc(int& x) {
    std::cout << "lvaluePassFunc(" << x << ")" << std::endl;
    return x;
}

void rvaluePassFunc(int&& x) {
    std::cout << "rvaluePassFunc(" << x << ")" << std::endl;
}

/*
--Compiler doesnt like--
    int&& func() {
        return 5;
    }

*/

/*

--Bad idea creates dangling references-
    int& funcss(int&& x) {
        return x;
    }

    --Dangling reference--
        int& bad = funcss(100 + 50);

    --Wont work--
        int x = 43;
        funcss(x);

    --Works but why would you do this?--
        int x = 42;
        int& ref = funcss(std::move(x));

    --No reason to do that though, just do this--
        int x = 43
        int ref = std::move(x);

*/