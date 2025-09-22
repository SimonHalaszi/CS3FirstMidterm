/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* member initialization list, initializers

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>

class SimpleClass {
    public:
        // Default/Basic constructor that uses initialization list and initializers
        SimpleClass(int simpInt = 0, double simpDouble = 0, char simpChar = '\0') 
        : simpInt_(simpInt), simpDouble_(simpDouble), simpChar_(simpChar) {}
        // Initializers invoked in order members are declared in class definition
        // not in order they appear in initialization list

        // Needed for members that are const or references

        // This WONT work
        /*
        SimpleClass(int simpInt = 0, double simpDouble = 0, char simpChar = '\0') 
        { simpInt_ = simpInt; simpDouble = simpDouble_; simpChar = simpChar_; }
         */

        friend std::ostream& operator<<(std::ostream& out, const SimpleClass& print) {
            out << print.simpInt_ << " " << print.simpDouble_ << " " << print.simpChar_;
            return out;
        }

    private:
        int simpInt_;
        double simpDouble_;
        const char simpChar_;
};

int main() {
    // Using initialization list
    SimpleClass obj = {1, 2.3, 'f'};

    std::cout << obj << std::endl;
}