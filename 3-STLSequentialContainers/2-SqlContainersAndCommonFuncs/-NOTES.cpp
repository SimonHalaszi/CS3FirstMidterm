#include <iostream>
int main() {
    
    /* ---------------------------------------------------- //

    * sequential containers and functions common for sequential containers

    STL Organization

    Idea: To seperate data storage from operations on it

    Concepts:
        - Container: Data structure that stores values organized in a
        certain manner
        - Iterator: Way to access values in a container
        - Algorithm: Way to manipulate data through iterator regardless
        of container type
        - Callback: Reference to code, way to customize algorithms
        operation.

    What is not in STL?
    Tree or graph structures: The idea is to provide client with
    the desired property and leave it up to the implementer to
    use the appropriate data structure to satisfy it.

    STL is template-based and extensible

    // ---------------------------------------------------- */

    /* ---------------------------------------------------- //

    Containers

    Container provides implementation of commonly used data structures

    Element - Stored data
        - Homogeneous: Elements of only one type
    
    Sequential Containers
        - Container adapters: Limit operations of sequential containers
        for specialized purpose

    // ---------------------------------------------------- */

    /* ---------------------------------------------------- //

    Sequential Containers

    std::vector - Random access to elements, amortized constant insertions
    in back, linear insertions elsewhere.

    std::deque (double-ended queue) - Random aaccess to elements, amortized
    constant insertion in front/back, linear elsewhere.

    std::list (doubly linked list) - Linear access to elements, constant
    insertion/deletion once located

    std::array (c++11) - Fixed size array, knows its size (unlike C-style)
    can be copied, returned, no insertion/deletion

    std::forward_list (singly linked list, c++11) - Forward search only,
    less memory for storage than list.

    // ---------------------------------------------------- */

    /* ---------------------------------------------------- //

    Container Declartion Syntax

    All containers are templates and hence are declared as such:

    container_class<type_parameter> container_name;

    example:
        vector<int> items;

    // ---------------------------------------------------- */

    /* ---------------------------------------------------- //

    Common Container Functions

    bool c.empty() const; // true if there are no elements in c
    int c.size() const; // number of elements in c
    itr c.erase(); // removes one or more specific elements of a container
    void c.clear(); // removes all elements from a container
    c = cc; // containers can be assigned
    c.swap(cc); // swaps contents of c and cc

    For sequential containers

    Whether push_back/pop_back or push_front/pop_front exist for container depends on container

    c.push_back(e) & c.push_front(e) // adds element to c
    c.pop_back() & c.pop_front() // removes last or first element, does not return it
    c.back() & c.front() // returns last or first element

    // ---------------------------------------------------- */

}


