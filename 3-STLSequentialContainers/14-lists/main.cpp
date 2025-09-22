/*
STL SEQUENTIAL CONTAINERS

* lists, list functions, specialized list functions

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <list>
#include <iostream>

int main() {
    std::list<int> l;

    // no indexing or iterator arithmetic because they wouldnt be constant time
    // constant time deletion and insertion of elements anywhere in the list
    // linear access to elements

    // Populate l
    // push_front and push_back for doubly linked list
    // constant time operations
    for(int i = 0; i < 10; ++i) {
        l.push_front(i);
        l.push_back(i * 2);
    }

    std::cout << "l: ";
    for(const auto& e : l) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // front() and back() are constant time and return front and back value
    std::cout << "front(): " << l.front() << std::endl;
    std::cout << "back(): " << l.back() << std::endl;

    // All update functions constant time
    std::cout << "pop_front() & pop_back()" << std::endl;
    std::cout << "l: ";
    for(const auto& e : l) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::list<int>::iterator it = l.begin();
    for(int i = 0; i < 5; ++i) {
        ++it;
    }

    // Constant time
    std::cout << "inserting 67 before 6th element" << std::endl;
    it = l.insert(it, 67);
    std::cout << "l: ";
    for(const auto& e : l) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Constant time
    std::cout << "erasing 67 we just inserted" << std::endl;
    it = l.erase(it);
    std::cout << "l: ";
    for(const auto& e : l) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // list has size(), resize() and empty() but not capacity()
    // not memory opaqe    

    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << l.empty() << std::endl;

    std::cout << "resize to 40. Uses T() default constructor for new elements" << std::endl;
    l.resize(40);
    std::cout << "l: ";
    for(const auto& e : l) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "resize to 10" << std::endl;
    l.resize(10);
    std::cout << "l: ";
    for(const auto& e : l) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    

    std::cout << "clear() is linear" << std::endl;
    l.clear();
    std::cout << "l: ";
    for(const auto& e : l) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Repopulate l
    std::cout << "repopulated l" << std::endl;
    for(int i = 0; i < 10; ++i) {
        l.push_front(i);
        l.push_back(i * 2);
    }

    std::cout << "l: ";
    for(const auto& e : l) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::list<int> d = {1, 3};
    std::cout << "new list std::list<int> d = {1, 3}" << std::endl;

    std::list<int>::iterator dit = d.begin();
    ++dit;

    std::list<int>::iterator lit1 = l.begin();
    ++lit1;

    std::list<int>::iterator lit2 = l.end();
    --lit2;   

    std::cout << "Range splice" << std::endl;
    std::cout << "d.splice(dit, l, lit1, lit2);" << std::endl;
    d.splice(dit, l, lit1, lit2);

    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "l: ";
    for(const auto& e : l) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "Or can splice all of l into d" << std::endl;
    std::cout << "d.splice(d.begin(), l);" << std::endl;
    d.splice(d.begin(), l);

    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Now fully empty
    std::cout << "l: ";
    for(const auto& e : l) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    

    std::cout << "d.remove(6)" << std::endl;
    d.remove(6);
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "d.unique() : Only does consecutive copies : Call on sorted list" << std::endl;
    d.unique();
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;   
    
    std::cout << "d.sort()" << std::endl;
    d.sort();
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    

    std::cout << "d.reverse()" << std::endl;
    d.reverse();
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    
    
    std::cout << "d.unique() : Only does consecutive copies : Call on sorted list" << std::endl;
    d.unique();
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;      

    std::list<int> dd = {18, 18, 16, 20, 25, 20};
    std::cout << "std::list<int> dd = {18, 16, 20, 25, 20};" << std::endl;    
    std::cout << "dd: ";
    for(const auto& e : dd) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    

    std::cout << "Sorting dd" << std::endl;
    dd.sort();
    std::cout << "dd: ";
    for(const auto& e : dd) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorting d" << std::endl;
    d.sort();
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    

    std::cout << "Merging dd into d" << std::endl;
    d.merge(dd);
    std::cout << "d: ";
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl; 
    
    std::cout << "dd: ";
    for(const auto& e : dd) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    
}