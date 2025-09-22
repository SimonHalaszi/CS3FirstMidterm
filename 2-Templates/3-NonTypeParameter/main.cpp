/*
TEMPLATES

* nontype parameters

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>

// Templated class declaration
// 'Size' is a nontype template parameter. Its explicitly an int.
// Notice 'Size' also has a default value
// Just like a parameter in a function! Just the parameter is for the templated class.
template<typename T, int Size = 1>
class TemplateClass{
    public:
        // Templated methods
        // size_ will use nontype parameter and items_ will be initialized to an array of default values
        TemplateClass() : size_(Size), items_{} {}
        T getMember(int index) const { return items_[index]; }
        void setItems(T val) { for(T& e : items_) { e = val; }}
        void print() const { for(const T& e : items_) { std::cout << e << " "; } }

    private:
        // Templated member variable
        const int size_;
        // Uses nontype parameter to set size of member array
        T items_[Size];
};

int main() {

    TemplateClass<int, 10> intObj;
    std::cout << "TemplateClass<int, 10>: ";
    intObj.print(); std::cout << std::endl;

    TemplateClass<double, 5> doubleObj;
    std::cout << "TemplateClass<double, 5>: ";
    doubleObj.print(); std::cout << std::endl;
    std::cout << "doubleObj.setItems(3.14): ";
    doubleObj.setItems(3.14);
    doubleObj.print(); std::cout << std::endl;

    TemplateClass<bool> boolObj;
    std::cout << "TemplateClass<bool>: ";
    boolObj.print(); std::cout << std::endl;
    std::cout << "Default value is 1 for size!" << std::endl;
}