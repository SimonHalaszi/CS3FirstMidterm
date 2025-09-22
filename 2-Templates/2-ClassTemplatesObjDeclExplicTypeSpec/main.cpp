/*
TEMPLATES

* class templates, object declaration, explicit type specification

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <string>
#include <iostream>

// Templated class declaration
template<typename T>
class TemplateClass{
    public:
        // Templated methods
        TemplateClass(T val = T()) : member_(val) {}
        T getMember() const { return member_; }
        void setMember(const T& val) { member_ = val; }
        void print() const { std::cout << member_; }
        void outOfLineFunc() const;

    private:
        // Templated member variable
        T member_;
};

/*
Out of line function definition must specify template property again.
They must also specify that TemplateClass is of type T
*/
template<typename T>
void TemplateClass<T>::outOfLineFunc() const {
    std::cout << "Woah im out of line! Here's T, " << member_ << std::endl;
}

/*
Out of line function definition must specify template property again.
Specialized templated method function. Will be used for specified type
Specific of what type TemplateClass is 
Compiler will know to use this function for double instantiations!
It will not generate an instantiation using the generic outOfLineFunc!
Useful if your type T needs some sort of special treatment.
*/
template<>
void TemplateClass<double>::outOfLineFunc() const {
    std::cout << "Woah im being used for doubles! Here's T, " << member_ << std::endl;
}

template<typename T>
void standingAlone(const T& genericValue) {
    std::cout << "Standing alone! Here's T, " << genericValue << std::endl;
}


int main() {
    // Declaring an object of TemplatClass. Explicitly specifying with type int.
    TemplateClass<int> objInt;

    std::string s = "Hello, World!";

    // Can also explicitly specify standalone functions
    standingAlone<std::string>(s);

    // Error no suitable conversion! Compiler knows objInt is an int. So mistakes cant happen.
    // objInt.setMember(s);

    objInt.setMember(3);
    objInt.print(); std::cout << std::endl; // 3
    objInt.outOfLineFunc(); std::cout << std::endl;

    // Declaring an object of TemplateClass. Compiler deduces type double.
    // ^ Implicitly specifying if you will.
    TemplateClass objDouble(3.14); // This is a newer thing to c++ (c++17)
    objDouble.print(); std::cout << std::endl; // 3.14
    objDouble.outOfLineFunc(); std::cout << std::endl;

    // Error no suitable conversion! Compiler knows objInt is an int. So mistakes cant happen.
    // objDouble.setMember(s);
}