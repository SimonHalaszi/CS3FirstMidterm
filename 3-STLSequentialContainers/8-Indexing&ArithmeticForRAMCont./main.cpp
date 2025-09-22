/*
STL SEQUENTIAL CONTAINERS

* indexing and iterator arithmetic for random access containers

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <deque>
#include <iostream>

int main() {

    /*
    
    Indexing operations and iterator arithmetic can be applied
    to random access containers and their iterators.

    Note: The design philosphy of the STL is as such. If the
    particular access interface / operation cant be done in
    constant time it wont be implemented. So while its certainly
    possible for a doubly linked list to have indexing and iterator
    arithmetic thats in O(n) time. So STL only implements iterator
    arithmetic and indexing for random access containers.

        Smaller Note: Map has 'indexing' operator, but its not at
        all comparable to standard indexing. Its a complete different
        operation that uses the same operator.
    
    */

    // Declareing d with intializer list
    std::deque<int> d = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::deque<int>::iterator it = d.begin();

    /*
    
    Iterator arithmetic - Adding/subtratcing intergers comparing
    iterators for inequality.

    Indexing - Will return d[n] element

    Below are equivalent examples of iterator arithmetic and
    indexing oeprations
    
    */

    std::cout << "it = d.begin(): *it: " << *(it) << std::endl; // 0
    std::cout << "d[0]: " << d[0] << std::endl; // 0

    // Will move the iterator 4 elements up the deque
    it += 4;

    std::cout << "it += 4: *it: " << *(it) << std::endl; // 4
    std::cout << "d[4]: " << d[4] << std::endl; // 4

    std::deque<int>::iterator it2 = it;
    std::cout << "it2 = it: *it2: " << *(it2) << std::endl; // 4
    std::cout << "d[4]: " << d[4] << std::endl; // 4

    it -= 2;

    std::cout << "it -= 2: *it: " << *(it) << std::endl; // 2
    std::cout << "d[2]: " << d[2] << std::endl; // 2

    if(it < it2) {
        std::cout << "it2 is at a later element" << std::endl;
    }

    // std::cout << "d[20]: " << d[20] << std::endl; // Undefined
}