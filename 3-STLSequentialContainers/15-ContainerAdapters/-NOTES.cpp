#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * container adapters

    - Use adapter pattern to modify a sequential underlying 
    container for specific purpose by limiting interface:
    NO iterators, NO indexing, FEW functions

    - Adapter pattern - A generic class that expects a type
    and a container type. Container is private so interface is 
    limited, but the public functions implement container functions.

    - size(), empty(), swap() are supported

    stack. First in Last out / Last in First out
        - Needs <stack> underlying default deque, possible vector, list
        - push() - adds to top
        - pop() - removes from top, does not return
        - top() - returns top element

    queue. First in First out / Last in Last out
        - Needs <queue> underlying default deque, possible list    
        NOT vector. no push_front() for vector
        - push() - adds to tail
        - pop() - removes from head, does not return
        - front(), back() - returns first/last element

    priority_queue. Highest Priority First Out / Lowest Priority Last Out
        - Needs <queue> underlying default vector, possible deque
        - push() / pop() - add/remove
        - top() - returns highest priority element
        - Underlying heap structure

        Note: type needs less than operator

    // ---------------------------------------------------- */
}


