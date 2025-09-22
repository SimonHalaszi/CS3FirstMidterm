#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * lists, list functions, specialized list functions

    std::list, include <list>

    - Implemented as doubly linked list
        - Supports constant time insertion/deletion of elements
        anywhere in the list.
        - Linear time for access to elements

    - No indexing or arithmetic on iterators - only increment/decrement
        - This is because implementations wouldnt be constant time
        but instead linear.

    - front(), back(), begin(), end() are constant time

    - Updating operations: push_front(), pop_front(), push_back(),
    pop_back(), emplace_back(), insert(), erase() are all implemented
    in constant time

    - clear() however is linear

    - size(), resize(), and empty() are supported but no capacity()
        - list is not memory opaque. Memory could be anywhere

    - splice() - constant time insert of another list to a posiition
    in this list - other list has its elements stripped.
        // range inside of list2
        list1.splice(list1.begin(), list2, list2Itr1, list2Itr2); 
        // all of list2
        list1.splice(list1.begin(), list2); 

    - remove(value) - removes all instances of a given value

    - unique() - eliminates CONSECUTIVE duplicates of values.
    use on sorted list for best result.

    - merge() - merges two sorted lists. not just unique values.

    - sort() - sorts a list

    - reverse() - reverses a list

    // ---------------------------------------------------- */
}


