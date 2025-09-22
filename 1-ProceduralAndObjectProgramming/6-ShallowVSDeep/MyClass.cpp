/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* shallow vs. deep copy

c++ main.cpp MyClass.hpp
./a.out > output.txt

*/

/*

* Simple dynamically allocated class to show off shallow vs. deep copy

*/

#include "MyClass.hpp"

// Copy constructor
MyClass::MyClass(const MyClass& copyMe) {
    this->size_ = copyMe.size_;
    this->intArr_ = new int[this->size_];
    for(int i = 0; i < this->size_; ++i) {
        this->intArr_[i] = copyMe.intArr_[i];
    }
}

// Shallow Copy Constructor
// Int just there to overload copy constructor into being bad
MyClass::MyClass(const MyClass& copyMe, int i) {
    // Ignore the i business just here to force a bad copy constructor
    i = 0;
    this->size_ = copyMe.size_ + i;
    this->intArr_ = copyMe.intArr_;
}

// Overloaded Assignment: Normal
MyClass& MyClass::operator=(const MyClass& copyMe) {
    if(this != &copyMe) {
        delete [] this->intArr_;
        this->size_ = copyMe.size_;
        this->intArr_ = new int[this->size_];
        for(int i = 0; i < this->size_; ++i) {
            this->intArr_[i] = copyMe.intArr_[i];
        }        
    }
    return *this;
}

// Shallow Assignment
MyClass& MyClass::shallowAssign(const MyClass& copyMe) {
    if(this != &copyMe) {
        delete [] this->intArr_;
        this->size_ = copyMe.size_;
        this->intArr_ = copyMe.intArr_; // Directly copying pointer
    }
    return *this;
}

// Some Funcs

// Defining default parameter at declaration
void MyClass::assignAll(int assigner = 0) {
    for(int i = 0; i < size_; ++i) {
        intArr_[i] = assigner;
    }
}

void MyClass::print() const {
    if(size_ <= 0) {
        std::cout << "empty ";
    }
    for(int i = 0; i < size_; ++i) {
        std::cout << intArr_[i] << " ";
    }
}