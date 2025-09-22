/*
STL SEQUENTIAL CONTAINERS

* sequential containers and functions common for sequential containers

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

// Our studied sequential containers
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <forward_list>

#include <iostream>
#include <string>

int main() {
    // Container declaration syntax
    // container_class<type_parameter> container_name;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "Container declaration syntax. container_class<type_parameter> container_name;" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    std::vector<int> intVector;
    std::cout << "std::vector<int> intVector;" << std::endl;
    
    std::deque<int> intDeque;
    std::cout << "std::deque<int> intDeque;" << std::endl;
    
    std::list<double> doubleList = {1.3, 4.3, 5.2, 1.3};
    std::cout << "std::list<double> doubleList = {1.3, 4.3, 5.2, 1.3}" << std::endl;

    std::forward_list<std::string> stringForwardList = {"st", "ri", "ng", "!"};
    std::cout << "std::forward_list<std::string> stringForwardList = {st, ri, ng, !};" << std::endl;

    std::array<std::string, 4> stringArray;
    std::cout << "std::array<std::string, 4> stringArray" << std::endl;    

    // Common Container Functions
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "Common Container Functions" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    
    //  c.empty() const; // True if there are no elements in c
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "c.empty() const; // True if there are no elements in c" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    if(intVector.empty()) {
        std::cout << "Yep, intVector is empty" << std::endl;
    } 

    // c.size() const; // Number of elements in container c
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "c.size() const; // Number of elements in container c" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "intDeque has " << intDeque.size() << " element(s) " << std::endl;

    // c.erase(); // removes one or more specific elements of the container
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "c.erase(); // removes one or more specific elements of the container" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    // For any container in STL you have range based for loops!
    // Use iterators and begin() and end() functions to interface with this loop type
    std::cout << "doubleList: ";
    for(const auto& e : doubleList) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    doubleList.erase(doubleList.begin());
    
    std::cout << "doubleList: ";
    for(const auto& e : doubleList) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    
    // c.clear(); // removes all elements from the container // no good for std::array
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "c.clear(); // removes all elements from the container // no good for std::array" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    std::cout << "stringForwardList: ";
    for(const auto& e : stringForwardList) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    stringForwardList.clear();

    std::cout << "stringForwardList: ";
    for(const auto& e : stringForwardList) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // c = cc; // replaces contents of c with contents of cc
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "c = cc; // replaces contents of c with contents of cc" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    std::array<std::string, 4> stringArrayTwo = {"st", "ri", "ng", "!"};
    std::cout << "stringArray: ";
    for(const auto& e : stringArray) {
        std::cout << e << " ";
    }
    std::cout << std::endl;      
    
    std::cout << "stringArrayTwo: ";
    for(const auto& e : stringArrayTwo) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    

    stringArray = stringArrayTwo;
    std::cout << "stringArray = stringArrayTwo;" << std::endl;

    std::cout << "stringArray: ";
    for(const auto& e : stringArray) {
        std::cout << e << " ";
    }
    std::cout << std::endl;      
    
    std::cout << "stringArrayTwo: ";
    for(const auto& e : stringArrayTwo) {
        std::cout << e << " ";
    }
    std::cout << std::endl; 
    
    // c.swap(cc); // swaps contents of c with contents of cc
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "c.swap(cc); // swaps contents of c with contents of cc" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    std::array<std::string, 4> stringArrayThree = {"!", "gn", "ir", "ts"};
    std::cout << "stringArray: ";
    for(const auto& e : stringArray) {
        std::cout << e << " ";
    }
    std::cout << std::endl;      
    
    std::cout << "stringArrayThree: ";
    for(const auto& e : stringArrayThree) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    

    stringArray.swap(stringArrayThree);
    std::cout << "stringArray.swap(stringArrayThree);" << std::endl;

    std::cout << "stringArray: ";
    for(const auto& e : stringArray) {
        std::cout << e << " ";
    }
    std::cout << std::endl;      
    
    std::cout << "stringArrayThree: ";
    for(const auto& e : stringArrayThree) {
        std::cout << e << " ";
    }
    std::cout << std::endl;   
    
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "For Sequential Containers" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "c.push_front() & c.push_back()" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    intVector.push_back(3); // no push_front
    std::cout << "intVector.push_back(3); // no push_front" << std::endl;
    intDeque.push_back(3); intDeque.push_front(3);
    std::cout << "intDeque.push_back(3); intDeque.push_front(3);" << std::endl;
    doubleList.push_back(3.14); doubleList.push_front(3.14);
    std::cout << "doubleList.push_back(3.14); doubleList.push_front(3.14);" << std::endl;
    stringForwardList.push_front("Howdy"); // no push_back
    std::cout << "stringForwardList.push_front(Howdy); // no push_back" << std::endl;
    // stringArray has no push. back or front. Its just a templated array.
    std::cout << "// stringArray has no push. back or front. Its just a templated array." << std::endl;

    std::cout << "intVector: ";
    for(const auto& e : intVector) {
        std::cout << e << " ";
    }
    std::cout << std::endl; 
    
    std::cout << "intDeque: ";
    for(const auto& e : intDeque) {
        std::cout << e << " ";
    }
    std::cout << std::endl; 

    std::cout << "doubleList: ";
    for(const auto& e : doubleList) {
        std::cout << e << " ";
    }
    std::cout << std::endl;     

    std::cout << "stringForwardList: ";
    for(const auto& e : stringForwardList) {
        std::cout << e << " ";
    }
    std::cout << std::endl;     

    std::cout << "stringArray: ";
    for(const auto& e : stringArray) {
        std::cout << e << " ";
    }
    std::cout << std::endl;      
    
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "c.pop_front() & c.pop_back()" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;  
    intVector.pop_back(); // no pop_front
    std::cout << "intVector.pop_back(); // no pop_front" << std::endl;
    intDeque.pop_back(); intDeque.pop_front();
    std::cout << "intDeque.pop_back(); intDeque.pop_front();" << std::endl;
    doubleList.pop_back(); doubleList.pop_front();
    std::cout << "doubleList.pop_back(); doubleList.pop_front();" << std::endl;
    stringForwardList.pop_front(); // no push_back
    std::cout << "stringForwardList.pop_front(); // no push_back" << std::endl;
    // stringArray has no pop. back or front. Its just a templated array.
    std::cout << "// stringArray has no pop. back or front. Its just a templated array." << std::endl;  
    
    std::cout << "intVector: ";
    for(const auto& e : intVector) {
        std::cout << e << " ";
    }
    std::cout << std::endl; 
    
    std::cout << "intDeque: ";
    for(const auto& e : intDeque) {
        std::cout << e << " ";
    }
    std::cout << std::endl; 

    std::cout << "doubleList: ";
    for(const auto& e : doubleList) {
        std::cout << e << " ";
    }
    std::cout << std::endl;     

    std::cout << "stringForwardList: ";
    for(const auto& e : stringForwardList) {
        std::cout << e << " ";
    }
    std::cout << std::endl;     

    std::cout << "stringArray: ";
    for(const auto& e : stringArray) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    
    
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "c.front() & c.back()" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;  

    std::cout << "intVector.front(): " << intVector.front() << " intVector.back(): " << intVector.back() << std::endl;
    std::cout << "intDeque.front(): " << intDeque.front() << " intDeque.back(): " << intDeque.back() << std::endl;
    std::cout << "doubleList.front(): " << doubleList.front() << " doubleList.back(): " << doubleList.back() << std::endl;
    // Repopulate stringForwardList since it was cleared and emptied earlier
    stringForwardList.push_front("Hey");
    std::cout << "stringForwardList.front(): " << stringForwardList.front() << " // no stringForwardList.back(): " << std::endl;
    std::cout << "stringArray.front(): " << stringArray.front() << " stringArray.back(): " << stringArray.back() << std::endl;
    
}