/*
STL SEQUENTIAL CONTAINERS

* deque and deque space allocation

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <deque>
#include <iostream>

int main() {
    // Doubled-Ended Queue
    // deque declration
    std::deque<int> d;

    // Main purpose: Pushing to front and back is constant time
    std::cout << "Pushing to front and back is constant time" << std::endl;
    d.push_front(10);
    std::cout << "d.push_front(10); " << std::endl;
    d.push_back(10);
    std::cout << "d.push_back(10); " << std::endl;

    // Indexing is a bit slower but still constant
    // This is because it takes a bit more math than normal index operation
    std::cout << "Constant time access d[0]: " << d[0] << std::endl;

    std::cout << "Adding a bunch of elements to d " << std::endl;
    std::cout << "Pushing with front and back, constant time" << std::endl;
    for(int i = 0; i < 10; ++i) {
        d.push_front(i);
        d.push_back(i);
    }

    std::cout << "Printing elements in d with constant time access" << std::endl;
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Insertions and deletions to the middle of deque are a consistent O(n) operation
    std::deque<int>::iterator it = d.begin();
    std::cout << "std::deque<int>::iterator it = d.begin();" << std::endl;
    it += 5; // Iterator arithmetic. More on this later
    std::cout << "it += 5; // Iterator arithmetic. More on this later" << std::endl;
    // Erasing element at the 5th index of d; O(N) operation
    d.erase(it);
    std::cout << "d.erase(it);" << std::endl;
    std::cout << "Erasing element at the 5th index of d; O(N) operation" << std::endl;

    std::cout << "Printing elements in d with constant time access" << std::endl;
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // deque is memory opaque: capacity() and reserve() are unaviable

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