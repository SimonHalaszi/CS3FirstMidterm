/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* rvalue references, scopes for r-value references, function returning rvalues

c++ main.cpp MyClass.hpp
./a.out > output.txt

*/

/*

* Simple dynamically allocated class to show off shallow vs. deep copy

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
        // Shallow Copy Constructor
        // Int just there to overload copy constructor into being bad
        MyClass(const MyClass&, int i);
        // Overloaded Assignment: Normal
        MyClass& operator=(const MyClass&);
        // Shallow Assignment
        MyClass& shallowAssign(const MyClass&);
        // Destructor
        // ~MyClass() { delete [] intArr_; }

        // Some Funcs
        void assignAll(int assigner);
        void print() const;
    private:
        int size_;
        int* intArr_;
};
