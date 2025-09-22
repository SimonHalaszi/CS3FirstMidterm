/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* rvalue references, scopes for r-value references, function returning rvalues

c++ main.cpp MyClass.hpp
./a.out > output.txt

*/

/*

* Simple dynamically allocated class to show off rvalue reference in move constructor and move assignment

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

// Move constructor
MyClass::MyClass(MyClass&& moveMe) noexcept {
    this->size_ = moveMe.size_;
    moveMe.size_ = 0;
    this->intArr_ = moveMe.intArr_;
    moveMe.intArr_ = nullptr;
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

// Overloaded Assignment: Move
// (copy-n-swap idiom is incompatbile with move assingment)
// Makes no sense to use it. Defeats whole purpose of move semantics
MyClass& MyClass::operator=(MyClass&& moveMe) {
    if(this != &moveMe) {
        delete [] this->intArr_;
        this->size_ = moveMe.size_;
        moveMe.size_ = 0;
        this->intArr_ = moveMe.intArr_;
        moveMe.intArr_ = nullptr;
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