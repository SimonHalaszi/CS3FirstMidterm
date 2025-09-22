#include <iostream>
int main() {
    
    /* ---------------------------------------------------- //

    * deque and deque space allocation

    Main purpose: Adding in front as well as back will be constant time

    Deque interface similar to vector, but
        - Implements constant push_front() and push_back()
        - Insertions/Deletes are more consistent in time
            - All O(n) other than front and back
        - Indexing is a tad bit slower
            - Requires a bit more arithmetic than simple
            sequential indexing of memory. But it is still
            constant and fast.
    Deque is memory opaque:
        capacity() and reserve() are unavailable

    Deque holds a map of blocks that access a fixed sized data block.
    The blocks being fixed sized is paramount. Otherwise it could not
    be a constant time access.

    Say I want to access deque[14] in a deque with data blocks of size
    5.

    // Something like the following will happen
    It would first do floor(14/5) = 2 so we know deque[14] is in the block[2]. 
    Then it does 14 - (2 * 5) = 4 so now we know element in data block
    is the 4th element in data block.

    That is more math than just doing the typical start address + (index * 
    element memory size) which is why indexing is slower. But this
    typical access calculation only works for sequential containers like
    vector and array. And sequential containers have properties that
    might not be desirable of course.

    The implementation of deque is similar to virtual memory paging. In the
    sense that keys hold a pointer to some sort of block in memory. 
    Paging more specifically is a list of pages that contain memory maps
    and these memory maps point to fixed sized data blocks. This is why
    memory in your computer is also random access! Thus why its called RAM
    (Random Access Memory)

    // ---------------------------------------------------- */

}


