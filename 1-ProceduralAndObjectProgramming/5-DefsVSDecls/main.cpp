/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* definitions vs. declarations for variables, functions classes

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>

// This is a variable declaration. 
/*
IN SOME SEPERATE FILE...
*/
extern int externInt;
static double staticDouble;

// This is a function declaration
// Default values for parameters here
double func(int a, const double& b, const char c = '\0');

// This is class declaration
class MyClass;

// Redundant to do this but showing distinction

// This is a class definition.
class MyClass {
    public:
        // Default Constructor and Constructor given values
        MyClass(int inty = 0, double dubby = 0, char c = '\0') : inty_(inty), dubby_(dubby), chary_(c) {}
        int getInty() const { return inty_; }
        int getDubby() const { return dubby_; }
        int getChary() const { return chary_; }
        void setDubby(const double& setter) { dubby_ = setter; }
    
    private:
        // Member variable declarations
        int inty_;
        double dubby_;
        char chary_;
};

int main() {
    /*
    
    For local variables, declaration and definition happen
    together. The distinction becomes important with extern variables,
    static variables with global scope and when separating interface
    from implementation.
    
    */

    char c = '6';

    // Variable definition
    int externInt;
    externInt = 10;
    staticDouble = 4.45;

    // When object is created the member variables are defined
    MyClass obj(externInt, staticDouble, c);

    double d = func(obj.getInty(), obj.getDubby(), obj.getChary());
    std::cout << "d: " << d << std::endl;
}

// This is a function definition.
/*

Variable names must be defined here in parameter list. But can also be in definition
Default values for parameters should be specified in declaration. You can also specify 
them in function definition but you can NOT specify them in both.

*/
double func(int a, const double& b, const char c) {
    double someDouble = a + b + c;
    return someDouble;
}    