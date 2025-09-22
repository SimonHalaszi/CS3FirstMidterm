/*
STL SEQUENTIAL CONTAINERS

* iterator, iterator operations, half-open range

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <deque>
#include <iostream>

int main() {

    // Making some sort of deque
    std::deque<int> d;
    for(int i = 1; i < 10; ++i) {
        d.push_back(i);
        d.push_front(i);
    }

    // Printing the d container
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Declare an iterator
    std::deque<int>::iterator it = d.begin();

    /*
    
    Iterator is a interface for containers to provide common way
    to manipulate all containers. Acts similar to a pointer but 
    iterator may not necessarily be a pointer.

    */

    // Iterator operations

    // Dereference, like pointers
    std::cout << *it << std::endl; // Will get value at it d[0]

    // Prefix and postfix increment
    std::cout << *(++it) << std::endl; // Will get value at d[1] is at d[1]
    std::cout << *(it++) << std::endl; // Will get value at d[1] but it is at d[2]

    std::cout << *(it--) << std::endl; // Will get value at d[2] but it is at d[1]
    std::cout << *(--it) << std::endl; // Will get value at d[0] is at d[0]

    // Iterator Comparison

    std::deque<int>::iterator it2 = d.begin();

    if(it == it2) {
        std::cout << "Yep they are equal" << std::endl;
    }
    if(it != it2) {
        std::cout << "I wont be printed" << std::endl;
    }

    // Member functions of containers that interface with iterators
    it = d.begin(); // Returns an iterator pointing to the first element of d
    it2 = d.end(); // Returns an iterator pointing just past the end of d

    /*
    
    end() is analogous to the nullptr. But unlike nullptr, you may apply
    decrement to iterator returned by c.end() to get an iterator to the last
    element.
    
    */

    // Half-open range 
    // A range that includes everything between two points but one of the ends
    // c.begin(), c.end() - all elements in the container with a half open range

    // This will get rid of every element in d
    d.erase(it, it2);

    // Printing the empty d container
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Repopulate d
    std::cout << "Repopulating d" << std::endl;

    for(int i = 1; i < 10; ++i) {
        d.push_back(i);
        d.push_front(i);
    }

    // Printing the d container
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Declare a const_iterator

    std::deque<int>::const_iterator itc = d.cbegin();
    std::deque<int>::const_iterator itc2 = d.cend();

    /*
    

    const_iterator means you can not directly interface
    through the iterator to alter the object. But you
    can interface within the containers methods itself
    using const_iterators.
    
    */

    // const_iterator can change
    itc++;
    itc--;

    // const_iterator cant directly change element. Wont work.
    // *itc = 10;

    // Can interface within the container using const_iterator
    d.erase(itc, itc2);

    // Printing the empty d container
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Iterator has arithmetic, like pointers

    // Repopulate d
    std::cout << "Repopulating d" << std::endl;

    for(int i = 1; i < 10; ++i) {
        d.push_back(i);
        d.push_front(i);
    }

    // Printing the d container
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    itc = d.cbegin();
    itc2 = d.cend();

    itc += 5;

    std::cout << "d[5]: " << *(itc) << std::endl;

    itc -= 2;

    std::cout << "d[3]: " << *(itc) << std::endl;

    // Actual const iterator exist but that works as any other const
    // Iterator itself cannot be moved to point elsewhere

    const std::deque<int>::iterator cit = d.begin();

    // Cant do
    // cit++;

    std::cout << *(cit) << std::endl;

}