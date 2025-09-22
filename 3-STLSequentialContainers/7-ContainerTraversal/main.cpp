/*
STL SEQUENTIAL CONTAINERS

* container traversal

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <deque>
#include <iostream>

int main() {

    std::deque<int> d;
    
    // Populate d
    for(int i = 0; i < 10; ++i) {
        d.push_back(i);
        d.push_front(i);
    }

    // Container traversal - Visit each element exactly one

    // Can be accomplished with iterators!

    std::cout << "d: ";
    for(std::deque<int>::const_iterator it = d.cbegin(); // Declaring const_iterator to begin of d
        it != d.cend(); // While it != d.cend(). 
        ++it) { // Increment iterator
            std::cout << *(it) << " ";
    }
    std::cout << std::endl;

    // Why not it < d.cend()? Because for non sequential-memory containers thats a problem.
    // it < it2 could be true even if it is later in the container. And proper implementation
    // of < might not be implemented for given container.

    // Can use auto!
    // Saves a lot of typing
    std::cout << "d: ";
    for(auto it = d.cbegin(); // Type of auto is deduced at compile time
        it != d.cend(); // While it != d.cend(). 
        ++it) { // Increment iterator
            std::cout << *(it) << " ";
    }
    std::cout << std::endl;

    // Better yet can use range-based for
    // Saves even more typing
    // Sementically the exact same as above 2 for loops
    std::cout << "d: ";
    for(const auto& e : d) { // Works with any construct with begin() and end() defined
        std::cout << e << " ";
    }

    // Note: if you dont pass-by reference this will pass-by value the actual element
    // range-based for with containers is implemented using iterators but the client
    // interface does not interact with them. So const and & are needed to maintain 
    // similar semantics.

}