#include <iostream>
int main() {
    
    /* ---------------------------------------------------- //

    * vectors and functions specific for vectors, vector space allocation
    memory transparency, capacity() and reserve()

    Need #include <vector>; using std::vector;

    Declaring, initializing
        vector<int> myVector;   // Vector with no elements
        vector<int> myVector = {1, 2, 3} // Initalizer list c++11

    Copying
        - Copy constructor and assignment operator
        perform deep copies of vectors: Use pass-by reference for
        effciency (Not copy-and-swap idiom)

    Comparing
        Vector overloads !=, <, >, <= and >=
        Lexicographic comparison: "Less than" is by first unequal element

    size() - current number of elements in the container 
        - In other words elements that have a intialized value, or 
        elements that are before the end() iterator

    resize() - Makes vector a specified size, discards extra elements

    Vector is memory transparent container:
        - capacity() - returns size of current vector buffer
            - capacity() >= size()
            - As vector grows, most implementations double the
            capacity when limit is reached
            - When vector shrinks capacity is usually not changed
    
    reserve() - allocates space but does not change size. 
        reserve(n) where n <= size() does nothing.

    // ---------------------------------------------------- */

}


