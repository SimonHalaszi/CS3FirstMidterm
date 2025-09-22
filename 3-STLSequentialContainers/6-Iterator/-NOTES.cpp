#include <iostream>
int main() {
    
    /* ---------------------------------------------------- //

    * iterator, iterator operations, half-open range

    Iterator - Abstraction for accessing elements of containers
        - Have specific interface regardless of container, hence
        common way to manipulate all containers
        - Is a design patter that is realized as language feature
        - Not necessarily a pointer

    Declaring iterator
        containter_class<type_parameter>::iterator_type iterator_name

        - containter_class - vector, deque, list, etc
        - type_parameter - type/class of elements
        - iterator_type - iterator, const_iterator, ( more later )
        - iterator_name - identifier

        EX:
        deque<int>::iterator it = d.begin();

    Iterator Operations

    Iterator Arithmetic
        - ++, -- (Pre and postfix)
        - == and !=
        - (*) dereferencing provides element access

    Member functions that give iterators for containers
        - c.begin() - Iterator pointing to first element
        - c.end() - Iterator pointing just past last element
            - Analogous to the null pointer. Unlike null pointer
            however you can apply decrement to iterator returned
            by c.end() to get an iterator pointing to last element

    Half-open range
        - A range between two points that contains all elements
        between them but excludes one of the ends
        - For half-open ranges in c++ this usually excludes the end point
            - c.erase(it, it2) // does not include it2
            - str.substr(1, 6) // does not include 6th index in substr
        - Since c.end() goes just past the last element c.begin(), 
        c.end() will be ALL elements in a container.

    const_iterator vs iterator
        - const_iterator just guarantees that provided iterator
        will not be used to directly alter the element it points
        to. But const_iterator is not const in itself. It can be
        iterated else where. And const_iterator does not mean
        it cant be used in container operations to alter container.
        c.erase(itc, itc2) where itc is const_iterator does work.

    // ---------------------------------------------------- */

}


