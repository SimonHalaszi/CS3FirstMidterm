#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * indexing and iterator arithmetic for random access containers

    Indexing operations and iterator arithmetic can be applied
    to random access containers and their iterators.

    Note: The design philosphy of the STL is as such. If the
    particular access interface / operation cant be done in
    constant time it wont be implemented. So while its certainly
    possible for a doubly linked list to have indexing and iterator
    arithmetic thats in O(n) time. So STL only implements iterator
    arithmetic and indexing for random access containers.

        Smaller Note: Map has 'indexing' operator, but its not at
        all comparable to standard indexing. Its a complete different
        operation that uses the same operator.

    Iterator arithmetic - Adding/subtratcing intergers comparing
    iterators for inequality.

    Indexing - Will return d[n] element

    Indexing out of bounds causes undefined behavior

    // ---------------------------------------------------- */
}


