/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* copy-and-swap idiom

c++ main.cpp MyClass.hpp
./a.out > output.txt

*/

/*

* Simple dynamically allocated class to show off copy-and-swap idiom

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
        // Overloaded Assignment: Normal
        MyClass& operator=(MyClass);
        void swap(MyClass&);
        // Destructor
        ~MyClass() { delete [] intArr_; }

        // Some Funcs
        void assignAll(int assigner);
        void print() const;
    private:
        int size_;
        int* intArr_;
};
