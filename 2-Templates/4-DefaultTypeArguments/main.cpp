/*
TEMPLATES

* default template arguments

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <string>

// Default values for template arguments can be set for both type and non-type parameters
template<typename T = int, int bud = 100>
class TemplateClass{
    public:
        // Templated methods
        TemplateClass(T val = T(), int buddy = bud) : member_(val), buddy_(buddy) {}
        T getMember() const { return member_; }
        void setMember(const T& val) { member_ = val; }
        void print() const { std::cout << member_ << " " << buddy_; }

    private:
        // Templated member variable
        T member_;
        const int buddy_;
};

int main() {
    // Uses default value for type and nontype!
    TemplateClass<> defaultObj;
    std::cout << "TemplateClass<> defaultObj: " << std::endl;
    defaultObj.print(); // 0 100
    std::cout << std::endl;

    TemplateClass<std::string> defaultWString;
    std::cout << "TemplateClass<std::string> defaultWString " << std::endl;
    defaultWString.print(); // ' ' 100
    std::cout << std::endl;

    TemplateClass<double, 431> doubleObj;
    doubleObj.setMember(3.14);
    std::cout << "TemplateClass<double, 431> doubleObj; \ndoubleObj.setMember(3.14); " << std::endl;
    doubleObj.print(); // 3.14 431
    std::cout << std::endl;

    /*
    
    // Cant do TemplateClass<154>. Default template parameters just like in functions
    // are to be used from left to right. So TemplateClass expects nothing, a type, or
    // a type and a integer. But not just an integer.   
    
    */
}