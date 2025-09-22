/*
STL SEQUENTIAL CONTAINERS

* emplace()

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

/*

Templated dynamically allocated class, to show off emplace()
and also to practice making a dynamically allocated template class.

*/

#include <iostream>

// Telling compiler templated class MyClass will exist
template<typename T>
class MyClass;

// Telling compiler that a operator overload of ==
// will exist for two MyClass of the same type
template<typename T>
bool operator==(const MyClass<T>&, const MyClass<T>&);

template<typename T>
class MyClass{
    public:
        // Default Constructor
        MyClass(int size = 0) : size_(size), array_(size_ > 0 ? new T[size] : nullptr) {}
        // Copy Constructor
        MyClass(const MyClass&);
        // Move Constructor
        MyClass(MyClass&&);
        // Destructor
        ~MyClass() { delete [] array_; }
        // Overloaded Copy Assignment
        MyClass& operator=(const MyClass&);
        // Overloaded Move Assignment
        MyClass& operator=(MyClass&&) noexcept;
        
        // Accessor
        int size() const { return size_; }

        // Modifier
        T* array() { return array_; }

        // Declare operator== as specific friend for T instatiations
        // operator==<T> is specifcally saying use operator== with same type as T
        friend bool operator==<T>(const MyClass<T>&, const MyClass<T>&);

    private:
        int size_;    
        T* array_;

};

// Copy Constructor
template<typename T>
MyClass<T>::MyClass(const MyClass<T>& inpObj) {
    this->size_ = inpObj.size_;
    this->array_ = new T[size_];
    for(int i = 0; i < this->size_; ++i) {
        this->array_[i] = inpObj.array_[i];
    }
}

// Move Constructor
// Leave moveObj in a safe but undefined (to client) state
template<typename T>
MyClass<T>::MyClass(MyClass<T>&& moveObj) {
    this->size_ = moveObj.size_;
    moveObj.size_ = 0;
    this->array_ = moveObj.array_;
    moveObj.array_ = nullptr;
}

// Copy Assignment
template<typename T>
MyClass<T>& MyClass<T>::operator=(const MyClass<T>& rhs) {
    if(this != &rhs) {
        delete [] this->array_;
        this->size_ = rhs.size_;
        this->array_ = new T[size_];
        for(int i = 0; i < this->size_; ++i) {
            this->array_[i] = rhs.array_[i];
        }
    }
    return *this;
}

// Copy-And-Swap idiom doesnt make sense for move assignment
// Move Assignment
// Leave moveObj in a safe but undefined (to client) state
template<typename T>
MyClass<T>& MyClass<T>::operator=(MyClass<T>&& moveObj) noexcept {
    if(this != &moveObj) {
        delete [] this->array_;
        this->size_ = moveObj.size_;
        moveObj.size_ = 0;
        this->array_ = moveObj.array_;
        moveObj.array_ = nullptr;
    }
    return *this;
}

// Define friend function
template<typename T>
bool operator==(const MyClass<T>& lhs, const MyClass<T>& rhs) {
    if(lhs.size_ != rhs.size_) {
        return false;
    }
    for(int i = 0; i < lhs.size_; ++i) {
        if(lhs.array_[i] != rhs.array_[i]) {
            return false;
        }
    }
    return true;
}
