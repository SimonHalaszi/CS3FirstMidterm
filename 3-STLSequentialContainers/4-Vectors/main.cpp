/*
STL SEQUENTIAL CONTAINERS

* vectors and functions specific for vectors, vector space allocation
  memory transparency, capacity() and reserve()

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <vector>
#include <iostream>

int main() {
    // Vector declaration
    std::vector<int> v;
    std::cout << "std::vector<int> v;" << std::endl;

    // Can use intializer list
    std::vector<double> vv = {3.14, 3.53, 23.6, 12.6};
    std::cout << "std::vector<double> vv = {3.14, 3.53, 23.6, 12.6};" << std::endl;

    // Vector has size() function // Current number of elements in the container
    std::cout << "// Vector has size() function // current number of elements in the container" << std::endl;
    std::cout << "v.size():" << v.size() << std::endl;
    std::cout << "vv.size():" << vv.size() << std::endl;

    // Vector has empty() function // Returns boolean value for if a vector is empty
    if(v.empty()) {
        std::cout << "v.empty() is true" << std::endl;
    }

    // Vector has resize() function // Makes vector specified size, discards extra elements
    std::cout << "// Vector has resize() function // Makes vector specified size, discards extra elements" << std::endl;
    std::cout << "vv.resize(2); " << std::endl;
    vv.resize(2);
    for(const auto& e : vv) {       // 3.14 3.53
        std::cout << e << " ";
    }
    std::cout << std::endl;
    std::cout << "Buffer capacity after vv.resize(2): " << vv.capacity() << std::endl;

    // resize() to bigger vector will use default constructor/value for type and allocate 
    // buffer of the given size.
    std::cout << "vv.resize(9); " << std::endl;
    vv.resize(9);
    for(const auto& e : vv) {       // 3.14 3.53 0 0 0 0 0 0 0
        std::cout << e << " ";
    }
    std::cout << std::endl;
    std::cout << "Buffer capacity after vv.resize(9): " << vv.capacity() << std::endl;

    // Vector is memory transparent container: below operations are available
    std::cout << "// Vector is memory transparent container: below operations are available" << std::endl;

    // capacity() - returns storage size current allocated to container. capacity() >= size()
    std::cout << "// capacity() - returns storage size current allocated to container. capacity() >= size()" << std::endl;

    std::cout << "vv.capacity(); - " << vv.capacity() << std::endl;  // 8

    std::cout << "As vector grows with push_back(), most implementations double capacity when buffer fills" << std::endl;

    std::cout << "Adding one more elements to full buffer of size " << vv.capacity() << std::endl;

    vv.push_back(10);
    std::cout << "vv.push_back(10);" << std::endl;

    std::cout << "vv.capacity(); - " << vv.capacity() << std::endl;  // 16

    // Vector has reserve() - allocates buffer with given space. But the size does not change.
    // So no default values added to vector, like with resize()
    std::cout << "Vector has reserve() - allocates buffer with given space. But the size does not change." << std::endl;
    std::cout << "So no default values added to vector, like with resize()" << std::endl;

    vv.reserve(32);
    std::cout << "vv.reserve(32);" << std::endl;

    for(const auto& e : vv) { // 3.14 3.53 0 0 0 0 0 0 10
        std::cout << e << " ";
    }
    std::cout << std::endl;


    // Reserving to a small value than size does nothing.    
    std::cout << "// Reserving to a small value than size does nothing." << std::endl;
    vv.reserve(2);
    std::cout << "vv.reserve(2);" << std::endl;

    for(const auto& e : vv) { // 3.14 3.53 0 0 0 0 0 0 10
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "vv.capacity(); - " << vv.capacity() << std::endl;  // 32

    // More explicit demonstration of vector filling up and doubling buffer
    std::cout << "// More explicit demonstration of vector filling up and doubling buffer" << std::endl;
    std::vector<int> vvv;
    std::cout << "std::vector<int> vvv;" << std::endl;

    vvv.push_back(1);
    std::cout << "vvv.push_back(1); Capacity of buffer: " << vvv.capacity() << std::endl; // 1
    vvv.push_back(1);
    std::cout << "vvv.push_back(1); Capacity of buffer: " << vvv.capacity() << std::endl; // 2
    vvv.push_back(1);
    std::cout << "vvv.push_back(1); Capacity of buffer: " << vvv.capacity() << std::endl; // 4
    vvv.push_back(1);
    std::cout << "vvv.push_back(1); Capacity of buffer: " << vvv.capacity() << std::endl; // 4
    vvv.push_back(1);
    std::cout << "vvv.push_back(1); Capacity of buffer: " << vvv.capacity() << std::endl; // 8

    // Buffer reallocation uses move semantics for elements getting moved to new buffer

}