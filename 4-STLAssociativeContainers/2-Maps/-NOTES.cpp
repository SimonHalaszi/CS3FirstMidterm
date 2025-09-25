#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * map, declaring, traversing, element lookup
    element inserting, range inserting
    element erasing

    Associative Containers
        - Do not store elements in linear order, provide mapping
        from keys to values
        - Usually insertion, deletion, lookup times are equivalent

    - Ordered Containers - Preserve order of elements implemented
    using a search tree
        - map - stores pairs, first element is key, lookup by key
        - multimap - map with multiple elements with same key
        - set - element and key are the same
        - multiset - duplicates of elements allowed

    - Unordered containers - c++11, do not order elements, quicker
    access implemented using hash tables
        - unordered_map
        - unordered_multimap
        - unordered_set
        - unordered_multiset

    MAPS

    Declaring and Traversing
        - Stored and sorted by key/value pairs
        - Sorting is based on key
        - Insertion/Deletion/Lookup takes O(log(n)) time
        - Need <map> and std::map
        - Declaring 
            - std::map<keyType, valueType> identifier
        - Traversing container
        - May iterate over map (in order of keys) to access elements
            for(std::map<keyType, valueType>::iterator it = m.begin();
                it != m.end();
                ++it;
            ) {
                // Touches all elements    
            }
            
            Note: iterator arithmetic not implemented, only postfix and prefix
            decrement and increment
        
            or use range-based for loop
        
    Lookups
        - With indexing
            map[key]; // Will get value at key
        - itr = find(key)
            - Returns iterator
            - Returns end() if not found
        - Range
            - Map has functions to make half open range between a left key value,
            where left end of range is no smaller than left key value, so 
            (lower_bound >= left key value)
            and with a right key value where right end of range is next greatest
            key value, so
            (upper_bound > right key value)
            - Creates half open range so that all elements between lower_bound
            and upper_bound, excluding upper_bound, are within range.
            - Both may return end() if the map is empty, or you put in a value
            greater than highest key value.
            - itr = lower_bound(1);
            - itr = upper_bound(2);
            - itrs that give all elements with keys 1, 2 up to 3 for example
    
    Inserting
        - const maps and maps of constant elements are allowed
        - Key is ALWAYS a const
        - Inserting
            
        "Unsafe" insert
            - Overloads indexing operator, overwrites old key value if it exists,
            creates a new pair in map if key value doesnt exist;
                - map[keyValue] = 10;
        
        "Safe" insert with insert()
            - Returns a pair with a iterator to a pair of the map, and a boolean
            to signify result of insertion
            - First pair element - iterator to existing or inserted map element
            - Second pair element - indicates whether insert was successful
                - true - element inserted
                - false - key already has value

        - Can insert with initializer list std::make_pair()
            - Returns iterator pair
            - map.insert({123, 'j'});
            - map.insert(std::make_pair(123, 'j'));

        - This pair of iterator and bool looks as such
            - std::pair<std::map<ktype, vtype>::iterator, bool>;

        - Can insert with a hint: Suggests optimal insertion position
            - Returns iterator to made or existing pair
            - May ignore hint if it's not optimal
            - For inserting the highest key value, map.end() is a good hint
            since the element will be inserted at the end
            - itr = map.insert(itr, {999, 'j'});
            - Same logic that if a modify function takes an itr to its object
            then it will return valid itr. Only exception we study is splice()
            for list.

        - Can insert range
            - Copies range from another tree
            - map2.insert(map1.begin(), map1.end());
            - If keys equal unspecified behavior
            - No return value

    Erasing
        - May erase at iterator or iterator range
            - Returns iterator to the next element past erased
            - it = m.erase(it);
            - it1 = m.erase(it1, it2);
        - Can also use erase(keyValue)
            - This returns number of nodes erased, useful for multimaps
        - clear() exist

    // ---------------------------------------------------- */
}


