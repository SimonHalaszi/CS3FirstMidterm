#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * unordered containers

    Unordered map - needs <unordered_map>, using std::unordered_map
        - Same interface as map
            - No lower_bound() or upper_bound() - container is not
            ordered
            - equal_range(key) does exist and gives you iterators
            that will give you a range containing everything with
            said key. [ 1 element in unordered_map ]
        - Plus: Transparent memory implementation
            - bucket_count() - number of buckets in hash table. 
            Occupied and unoccupied
            - load_factor() - size()/bucket_count() - How full
            the hashtable is
            - max_load_factor() - returns or sets maximum load
            factor size before bucket count increases. 1 by default
            - bucket(key) - will give the bucket index that contains
            key elements.
            - begin(key), end(key) - returns local_iterator for the 
            chain of elements in a bucket

        local_iterator - An iterator that traverses only the 
        elements within a single bucket of a hash table, rather
        than the entire container.

            - Purpose: Lets you inspect which elements are
            stored together in the same bucket.

    Unordered set - needs <unordered_set>, using std::unordered_set
        - Same interface as set with above functions

    Unordered multipmap and multisey exist with expected interfaces

    // ---------------------------------------------------- */
}


