/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* rvalue references, scopes for r-value references, function returning rvalues

c++ main.cpp MyClass.hpp
./a.out > output.txt

*/

/*

* Simple dynamically allocated class to show off rvalue reference in move constructor and move assignment

*/

#include <vector>
#include <iostream>

class MyClass {
    public:
        // Default constructor and constructor given an int
        // Can do both in one definition using default parameter
        MyClass(int size = 0) : size_(size) { size <= 0 ? intArr_ = nullptr : intArr_ = new int[size]; }
        // Copy constructor
        MyClass(const MyClass&);
        // Move constructor
        MyClass(MyClass&&) noexcept;
        // Overloaded Assignment: Normal
        MyClass& operator=(const MyClass&);
        // Overloaded Assignment: Move
        MyClass& operator=(MyClass&&);
        // Destructor
        ~MyClass() { delete [] intArr_; }

        // Some Funcs
        void assignAll(int assigner);
        void print() const;
    private:
        int size_;
        int* intArr_;
};
