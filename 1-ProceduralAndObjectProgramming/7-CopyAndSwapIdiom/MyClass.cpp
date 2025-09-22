/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* copy-and-swap idiom

c++ main.cpp MyClass.cpp
./a.out > output.txt
rm ./a.out

*/

/*

* Simple dynamically allocated class to show off copy-and-swap idiom

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

// Overloaded Assignment: Constant time swap
// copy-and-swap idiom does not work for move assignment
MyClass& MyClass::operator=(MyClass rhs) {
    swap(rhs);
    return *this;
}

void MyClass::swap(MyClass& rhs) {
    int tempSize = this->size_;
    this->size_ = rhs.size_;
    rhs.size_ = tempSize;
   
    int* tempArr = this->intArr_;
    this->intArr_ = rhs.intArr_;
    rhs.intArr_ = tempArr;
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