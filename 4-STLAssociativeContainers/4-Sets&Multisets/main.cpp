/*
STL ASSOCIATIVE CONTAINERS

* sets, multisets

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <set>
#include <iostream>

int main() {
    // key and value are same thing (Not actually a pair)

    // set and multiset
    std::set<int> s; std::multiset<int> ss;

    // Inserts

    // Insert returns pair of iterator to insert and bool just like map
    std::pair<std::set<int>::iterator, bool> insResult;

    insResult = s.insert(1);
    if(insResult.second) {
        std::cout << "s.insert(1) was good: " << *(insResult.first) << std::endl;
    }
    insResult = s.insert(4);
    if(insResult.second) {
        std::cout << "s.insert(4) was good: " << *(insResult.first) << std::endl;
    }
    insResult = s.insert(1);
    if(!insResult.second) {
        std::cout << "s.insert(1) was bad! no duplicates: " << *(insResult.first) << std::endl;
    }    

    // Elements are kept sorted
    // Does not implement indexing

    // insert types
    // Normal insert
    insResult = s.insert(8);
    if(insResult.second) {
        std::cout << "s.insert(8) was good: " << *(insResult.first) << std::endl;
    }        

    std::cout << "s: ";
    for(const auto& e : s) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Elements in set are constant and cannot be changed. But they can be erased

    // hint insert
    // Only returns iterator because you want to nicely update iterator
    // used in function call
    std::set<int>::iterator it = s.end();
    it = s.insert(it, 20);

    std::cout << "s: ";
    for(const auto& e : s) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    

    std::set<int> os;
    os.insert(1);
    os.insert(3);
    os.insert(6);
    os.insert(9);

    std::cout << "os: ";
    for(const auto& e : os) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    

    // range insert from other set
    // does not return anything
    s.insert(os.begin(), os.end());
    std::cout << "s: ";
    for(const auto& e : s) {
        std::cout << e << " ";
    }
    std::cout << std::endl;        

    // Erases
    
    // Value erase
    s.erase(1); // gets rid of 1 // returns number of erased elements useful for multiset
    std::cout << "s: ";
    for(const auto& e : s) {
        std::cout << e << " ";
    }
    std::cout << std::endl; 
    
    // Iterator erase // returns iterator for loop-modification
    // find function also exist for set
    it = s.erase(s.find(3));
    std::cout << "s: ";
    for(const auto& e : s) {
        std::cout << e << " ";
    }
    std::cout << std::endl; 
    
    // range erase
    it = os.begin();
    ++it;
    ++it;
    os.erase(os.begin(), it); // will erase from os.begin() up to 3rd element
    std::cout << "os: ";
    for(const auto& e : os) {
        std::cout << e << " ";
    }
    std::cout << std::endl;        

    // Standard clear function
    os.clear();
    std::cout << "os: ";
    for(const auto& e : os) {
        std::cout << e << " ";
    }
    std::cout << std::endl;        

    // Multiset is the same thing but duplicates can exist
    std::multiset<int>::iterator ssit;
    
    ssit = ss.insert(1); // Insert wont fail so not iterator pair
    ssit = ss.insert(1); // Works! Can have duplicates
    ssit = ss.insert(1);
    ssit = ss.insert(1);
    ssit = ss.insert(3);
    ssit = ss.insert(5);
    ssit = ss.insert(5);
    ssit = ss.insert(5);
    ssit = ss.insert(6);
    ssit = ss.insert(6);   

    std::cout << "ss: ";
    for(const auto& e : ss) {
        std::cout << e << " ";
    }
    std::cout << std::endl;        

    // lower_bound and upper_bound work similar to maps 
    // Will erase all elements from the start of the 1 elements to
    // the start of 5 elements. Half open range. upper_bound(3) 
    // returns iterator to first element greater than 3 (which is 5).
    ss.erase(ss.lower_bound(1), ss.upper_bound(3));

    std::cout << "ss: ";
    for(const auto& e : ss) {
        std::cout << e << " ";
    }
    std::cout << std::endl;    

    // Gets rid of all sixes
    int num = ss.erase(6);
    std::cout << "there was this amount of sixes: " << num << std::endl;

    std::cout << "ss: ";
    for(const auto& e : ss) {
        std::cout << e << " ";
    }
    std::cout << std::endl;        

    // Multiset has all same functionality just with duplicates allowed

    // equal_range exist
    std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> fiveRange = ss.equal_range(5);
    ss.erase(fiveRange.first, fiveRange.second);

    std::cout << "ss: ";
    for(const auto& e : ss) {
        std::cout << e << " ";
    }
    std::cout << std::endl;  
}