/*
STL SEQUENTIAL CONTAINERS

* random access containers

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <vector>
#include <deque>
#include <iostream>

int main() {
    // A random access container is any container were access is in constant time

    // Random access containers we study are std::vector<> and std::deque<>
    std::vector<int> v;

    // Insertion in vector either O(1) or O(n) ammoritzed to -> O(1)
    //                                         [ O(n) insertion gets more and more rare ]
    for(int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    // Constant time access of e
    std::cout << v[0] << std::endl;
    std::cout << v[4] << std::endl;
    std::cout << v[9] << std::endl;    

    std::deque<int> d;

    // Insertion to front and back of deque is an O(1) operation
    // Insertion in the middle of a deque is O(n)
    for(int i = 0; i < 10; ++i) {
        d.push_front(i);
        d.push_back(i);
    }

    // Constant time access of e
    std::cout << d[0] << std::endl;
    std::cout << d[9] << std::endl;
    std::cout << d[19] << std::endl;

    // This for loop in itself though is O(n)
    for(const auto& e : v) {
        // Constant time access of e
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // This for loop in itself though is O(n)
    for(const auto& e : d) {
        // Constant time access of e
        std::cout << e << " ";
    }    
    std::cout << std::endl;

    /*
    
    Deque implementation is actually pretty similar to how paging and
    virtual memory work in OS. This is why memory is random access.

    Deque has map with block keys that access a fixed sized data block.
    Finding an element can be done with some simple math.

    Virtual memory paging is with a list of pages that point to a memory
    map of a fixed size. And this memory map accesses a fixed sized
    data block.
    Going to an address in memory can be done with some simple math.

    Say our deque implements a block size of 5, our deque will look 
    something like this internally.

    map to data blocks           data block structure

    unused...
    block 0 -------------------> data block 0
    block 1      Start ptr ---> [ 9         ]
    block 2                     [ 8         ]
    block 3                     [ 7         ]
    unused...                   [ 6         ]
                                [ 5         ]

    */

}