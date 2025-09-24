/*
STL ASSOCIATIVE CONTAINERS

* multimaps, specifics and difference from maps

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <utility>
#include <map>
#include <iostream>

int main() {

    std::multimap<int, char> mm;

    mm.insert({1, 'c'});
    mm.insert(std::make_pair(1, 'd'));

    std::pair<int, char> pair = {1, 'e'};

    mm.insert(pair);

    mm.insert(std::make_pair(2, 'd'));
    mm.insert(std::make_pair(2, 'd'));
    mm.insert(std::make_pair(3, 'e'));

    for(const auto& e : mm) {
        if(e.first == 1) {
            std::cout << "char with key 1: " << e.second << std::endl;
        }
    }

    // No indexing operator

    // elements with same key are stored together
    // find() returns iterator to one of elements (not guaranteed first)

    std::multimap<int, char>::iterator it = mm.find(1);

    std::cout << "we got char: " << it->second << std::endl;

    // lower_bound(key) will give you first element with given key

    it = mm.lower_bound(1);

    std::cout << "we got c: " << it->second << std::endl;

    // lower_bound(key1) and upper_bound(key2) works same as map

    // Will get rid of all of the values with key 1 (End of half open range is 2)
    mm.erase(mm.lower_bound(1), mm.upper_bound(1));

    std::cout << "mm: " << std::endl;
    for(const auto& e : mm) {
        std::cout << "e.first: " << e.first
        << " e.second: " <<  e.second << std::endl;
    }    

    // Repopulate 1
    mm.insert(std::make_pair(1, 'd'));
    mm.insert(std::make_pair(1, 'd'));
    mm.insert(std::make_pair(1, 'e'));

    std::cout << "mm: " << std::endl;
    for(const auto& e : mm) {
        std::cout << "e.first: " << e.first
        << " e.second: " <<  e.second << std::endl;
    }

    // Will get rid of all of the values with key 1 and 2 (End of half open range is 3)
    mm.erase(mm.lower_bound(1), mm.upper_bound(2));    

    std::cout << "mm: " << std::endl;
    for(const auto& e : mm) {
        std::cout << "e.first: " << e.first
        << " e.second: " <<  e.second << std::endl;
    }

    // Repopulate 1 and 2
    mm.insert(std::make_pair(1, 'd'));
    mm.insert(std::make_pair(1, 'd'));
    mm.insert(std::make_pair(1, 'e'));    
    mm.insert(std::make_pair(2, 'd'));
    mm.insert(std::make_pair(2, 'd'));
    mm.insert(std::make_pair(2, 'e'));  
    
    std::cout << "mm: " << std::endl;
    for(const auto& e : mm) {
        std::cout << "e.first: " << e.first
        << " e.second: " <<  e.second << std::endl;
    }

    // Of type
    // std::pair<std::multimap<int, char>::iterator, std::multimap<int, char>::iterator>
    auto pairRange = mm.equal_range(1);

    // Will also get rid of all elements with key 1
    mm.erase(pairRange.first, pairRange.second);

    std::cout << "mm: " << std::endl;
    for(const auto& e : mm) {
        std::cout << "e.first: " << e.first
        << " e.second: " <<  e.second << std::endl;
    } 
    
    // Repopulate 1
    mm.insert(std::make_pair(1, 'd'));
    mm.insert(std::make_pair(1, 'd'));
    mm.insert(std::make_pair(1, 'e'));  
    
    // These ranges functions have much better uses than erasing because in reality you can
    // just do this

    // Will also get rid of all elements with key 1
    mm.erase(1);

    mm.insert({1, 'd'});

    std::cout << "mm: " << std::endl;
    for(const auto& e : mm) {
        std::cout << "e.first: " << e.first
        << " e.second: " <<  e.second << std::endl;
    }     
}