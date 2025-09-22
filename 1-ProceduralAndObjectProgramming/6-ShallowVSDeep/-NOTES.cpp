#include <iostream>

int main() {


    /* ---------------------------------------------------- //

    * shallow vs. deep copy

    Objects with dynamically allocated members
        - Have a member pointer that holds some sort of
        dynamically allocated memory, uses 'new' keyword.

    -- THE BIG THREE --
    Called such because these 3 must be implemented for ANY
    dynamically allocated class to function properly with
    the normal semantics of c++

    Copy Constructor
        - A constructor that initializes another object 
        of the same class to have the same state as
        the given object to copy.

    Destructor
        - Deallocates all dynamically allocated members

    Overloaded Assignment
        - An overload of assignment operator that handles 
        assignment semantics for a class.

    -- END --

    this
        - A keyword in c++. Its a pointer to the object
        that the current function was invoked by.

    Shallow copy
        - Memberwise copying of object attributes
        - Inadequate in case object has dynamically allocated
        members.
        - Pointers that hold dynamic memory will point to same
        dynamic variables.

    Deep copy
        - When copying or assigning a dynamically allocated
        object into another a deep copy is the process of
        allocating new memory for the 'this' object to copy
        the other object.
        - Pointers will point to different dynamic variables
        that have the same values.
        - Prevents double freeing and side effects
    
    // ---------------------------------------------------- */
}



