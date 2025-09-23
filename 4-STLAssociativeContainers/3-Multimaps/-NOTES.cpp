#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * multimaps, specifics and difference from maps

    - May store several elements with same key
    - Interface similar to maps
        - Does not provide indexing operator (does not make sense)
    - Lookup
        - Elements with same key are stored together
        - find(key) returns iterator to ONE OF elements with the given
        key. Not necessarily first. Just grabs the quickest one to get
        - lower_bound(key1), upper_bound(key2) - same operation as for
        map. 
            - Say we have multimap with keys with values 1, 2, and 3
            So lower_bound(1) will give the start of key 1
            and upper_bound(2) will give the start of key 3.
        - equal_range(key) returns a pair of iterators for the
        range. 
            - Given equal_range(1) with above multimap you would
            get first = start of 1 and second = start of 2. So that
            this is a half open range.

    - Updates: Same as map
        - erase(key) removes all elements with key, returns number of
        elements erased.

    // ---------------------------------------------------- */
}


