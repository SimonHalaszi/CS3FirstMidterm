#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * sets, multisets

    Set
        - A set of unique elements
        - Need <set>, using std::set
        - Keeps elements sorted
        - Does not implement indexing (nothing to index)
        - Since the element of the set is its own 'key'
        it is const and cannot be modified
            - If you want to update use erase() then insert()
        - All expected inserts exist
            - insert(element); // returns iterator, bool pair
            Same as map.
            - insert(it, element); // hint insert, returns iterator
            Same as map.
            - s.insert(os.begin(), os.end()); // inserts elements
            from another sets given range
        - All expected erases
            - erase(element); // gets rid of element, returns
            number of elements erased (useful for multiset,
            always 0 or 1 for set).
            - erase(it); // gets rid of element at iterator
            returns iterator to element after this element.
            - erase(it1, it2); // gets rid of all elements
            starting at it1 and up to it2. Half-open range
            - clear(); // clears the whole set
        - find(), lower_bound(), upper_bound()
            - All exist for set and work the exact same as map
     
    Multiset
        - Differences
            - Duplicates of elements allowed
            - insert(element) // Only returns iterator because
            insertion always succeeds (duplicates allowed)
            - erase(element); // Gets rid of all instances of
            element, returns num
            - equal_range(element) // Returns pair of iterators
            that provide half open range containing all instances
            of element. For set, range contains at most 1 element,
            but provides consistent interface with multiset.

    // ---------------------------------------------------- */
}


