#include <iostream>

int main() {
    

    /* ---------------------------------------------------- //

    * copy-and-swap idiom

    An idiom used primarily for overloaded assignment for
    dynamically allocated objects.

    Implements overloaded assignment by using pass-by value
    for right hand operand (copy). Then overloaded assignment
    calls a swap function with the copy.

    This swap function does a per member constant swap of this
    and the copy. This swap happens in constant time. But
    the copy happens in o(n).

    The copy goes out of scope and gets destructed at the end
    of the overloaded assignment call.

    More exception safe than normal overloaded assignment. If
    memory cannot be allocated for copy, the original is unchanged
    But has potential to waste more time. If I assign an object 
    to itself it wastes time making an unnecessary copy.

    // ---------------------------------------------------- */
}



