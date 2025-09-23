/*
STL ASSOCIATIVE CONTAINERS

* unordered containers

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <unordered_map>
#include <unordered_set>
#include <iostream>

int main() {
    // Unordered map
    std::unordered_map<int, char> um;

    // Pretty much same interface as map
    // no lower_bound() and upper_bound() as that requires sorted structure
    
    for(int i = 0; i < 10; ++i) {
        um.insert(std::make_pair(i, ('a' + i)));
    }

    std::cout << "um: " << std::endl;
    for(const auto& e : um) {
        std::cout << "key: " << e.first << std::endl
        << "element: " << e.second << std::endl;
    }

    // Is memory transparent
    std::cout << um.bucket_count() << std::endl; // number of buckets currently in hash table
    std::cout << um.load_factor() << std::endl; // how full hash table is
    std::cout << um.max_load_factor() << std::endl; // what load_factor can reach before more buckets
    um.max_load_factor(.9); // Can set load factor. 90% full = give me more buckets right now. Default 1

    int bucketIndex = um.bucket(1); // gives bucket index for bucket that contains key
    std::cout << bucketIndex << std::endl;

    std::cout << um[1] << std::endl; // Always 'b' - key 1 maps to 'b' regardless of which bucket it's in

    // local_iterator is an iterator used to interface with the buckets. Much more
    // useful for say unordered_multimap where buckets would have a range of data

    // These iterators would give you all the elements in the same bucket as key 1
    // (Which in just a map is just 1 element, but could include other keys that hash to same bucket)
    std::unordered_map<int, char>::local_iterator lit1 = um.begin(um.bucket(1));
    std::unordered_map<int, char>::local_iterator lit2 = um.end(um.bucket(1));

    um.equal_range(1); // Does exist. Will give you range of iterators that gives you everything with key 1

    // Unorded set, multimap, and multiset exist with expected interfaces
}