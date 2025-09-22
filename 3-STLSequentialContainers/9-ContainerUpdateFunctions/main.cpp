/*
STL SEQUENTIAL CONTAINERS

* container update functions, iterator invalidation, loop modification idiom

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <deque>
#include <vector>
#include <iostream>

int main() {

    /*
    
    Many different update functions for sequential containers!

    */
    
    /*

    insert() - for all sequential containers other than std::array and std::forward_list

    insert(position, value);  // value insert
    insert(position, repeats, value); // fill insert
    insert(position, from, to); // will insert a range of elements to position

    forward_list has insert_after same overloads just will insert after position

    We did not study forward_list in class to heavily so ignoring it here
    
    */

    // Any given sequential container
    std::deque<int> d = {0, 1, 2, 3, 4, 5};
    std::cout << "d: " << std::endl;
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::deque<int>::iterator it = d.begin();

    d.insert(it, 0); // 0, 0, 1, 2, 3, 4, 5
    std::cout << "d: " << std::endl;
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Revalidate
    it = d.begin();
    it += 2;

    d.insert(it, 2, 1); // 0, 0, 1, 1, 1, 2, 3, 4, 5
    std::cout << "d: " << std::endl;
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Revalidate
    it = d.begin();
    it += 2;

    d.insert(it, d.begin(), d.end()); // 0, 0, 0, 0, 1, 1, 1, 2, 3, 4, 5, 1, 1, 1, 2, 3, 4, 5
    std::cout << "d: " << std::endl;
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    
    /*

    erase() - for all sequential containers other than std::array and std::forward_list

    erase(position);
    erase(from, to);

    forward_list has erase_after same overloads just will erase after position

    We did not study forward_list in class to heavily so ignoring it here
    
    */

    // Revalidate
    it = d.begin();
    it += 2;    

    d.erase(it); // 0, 0, 0, 1, 1, 1, 2, 3, 4, 5, 1, 1, 1, 2, 3, 4, 5
    std::cout << "d: " << std::endl;
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Revalidate
    it = d.begin();
    it += 4;    

    d.erase(it, d.end()); // 0, 0, 0, 1
    std::cout << "d: " << std::endl;
    for(const auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;   
    
    /*

    assign() - for all sequential containers

    assign(from, to); // Replaces contents of callee with copies of contents
                         of inputted range, which could be of different container
                         type. Also works with intializer list.
    
    */

    std::vector<int> v;

    v.assign(d.begin(), d.end()); // v has same contents as d
    std::cout << "v: " << std::endl;
    for(const auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;  


    /*

    You might have seen "// Revalidate", why?

    For sequential containers update operations could possibley invalidate
    iterators in the containers, due to potential storage reallocation
        vector: all iterators past the point of insertion unless capacity reached
        deque: all iterators unless insertion is at front/back
        list: iterators unaffected

    erase() - returns iterator to next element past erased
    insert() - returns iterator to the first of the inserted elements

    These returned iterators can be used to keep iterator validated without extra
    lines of code, and while keeping it in the desired spot.


    Loop-modification idiom
    
    Way of modifying idiom as you traverse it

    */

    // Loop-modification idiom

    // Get rid of all the 0's in v using it while keep it validated
    // Idiom works for all sequential containers
    for(auto it = v.begin(); it != v.end();) {
        if(*it == 0) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }

    std::cout << "v: " << std::endl;
    for(const auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;  
}