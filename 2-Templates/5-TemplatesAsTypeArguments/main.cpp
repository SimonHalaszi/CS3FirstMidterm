/*
TEMPLATES

* templates as type arguments

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <vector>

// From before
template<typename T>
class TemplateClass{
    public:
        // Templated methods
        TemplateClass(T val = T()) : member_(val) {}
        const T& getMemberRef() const { return member_; }
        void setMember(const T& val) { member_ = val; }
        void print() const { std::cout << member_; }

    private:
        // Templated member variable
        T member_;
};

int main() {

    // Templates can be used as type arguments!
    // Works exactly as you would expect! No changes needed! Pretty awesome.
    TemplateClass<TemplateClass<int>> inception;
    std::cout << "TemplateClass<TemplateClass<int>> inception: " << std::endl;

    inception.getMemberRef().print(); // 0
    std::cout << std::endl;

    // Worth noting TemplateClass is very rudimentary so missing a lot of cool stuff you can do here.

    // Lets use vectors!

    std::vector<std::vector<int>> vectorOfIntegerVectors;
    std::cout << "std::vector<std::vector<int>> vectorOfIntegerVectors: " << std::endl;

    /*
    
    Not totally relevant but enforcing prior knowledge
    
    Showing off std::move a bit! 
    tempGuy is an xvalue from the point of view of vectorOfIntegerVectors.
    But we dont want to redo all this work to push tempGuy onto vectorOfIntegerVectors
    so we use std::move to use vector<int>'s move constructor and get him in there
    before he is gone forever!

    std::move will return the rvalue reference of tempGuy so that compiler knows
    tempGuy should be treated as an rvalue (specifically xvalue) and should use
    move constructor to give his buffer to the vector<int> object we create
    using push_back.
    
    */
    {
        std::vector<int> tempGuy;
        for(int i = 0; i < 20; ++i) {
            tempGuy.push_back(i);
        }
        vectorOfIntegerVectors.push_back(std::move(tempGuy));
    }

    {
        std::vector<int> tempGuy;
        for(int i = 0; i < 20; ++i) {
            tempGuy.push_back(i + 20);
        }
        vectorOfIntegerVectors.push_back(std::move(tempGuy));
    }

    // Nested for loop for our std::vector<std::vector<int>>
    for(const auto& integerVector : vectorOfIntegerVectors) {
        for(const auto& inty : integerVector) {
            std::cout << inty << " ";
        }
        std::cout << std::endl;
    }

}