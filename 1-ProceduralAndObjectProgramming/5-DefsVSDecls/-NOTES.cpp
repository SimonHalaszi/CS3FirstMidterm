#include <iostream>

    /* ---------------------------------------------------- //

    * definitions vs. declarations for variables, functions classes

    Declaration:
        Variables:
        When a given variable is given a name and type. For Local variables 
        this is at the same time as definition. Global static variables, 
        extern variables, and member variables, have a distincition between 
        the two. As those are first declared and then given memory space later.
        Where the giving of a name and type happens is the declaration 
    */

        // Examples of variable declaration. If in some seperate file.
        extern int declareExtern;
        static int declareStatic;

        class example{
            public:
                int a;
        };
    /*
        Function:
        Where the function is given its return type, name, parameter types,
        and parameter default values.
        Class:
        Where the class is given its name.
    */

int main() {
    /*    
    Definition:
        Variables: 
        When a given variable is allocated its memory. For Local variables 
        this is at the same time as declaration. Global static variables, 
        extern variables, and member variables, have a distincition between 
        the two. As those are first declared and then given memory space later. 
        Where this instantiation of memory happens is the definition.
    */

        // Examples of variable Definition
        int declareExtern;
        declareStatic = 10;

        example obj; // obj.a gets defined here
    /*        
        
        
        Functions:
        Where the body of code (The implementation) of the function is.
        Classes:
        Where the body of code (The implementation) of the class is.

    // ---------------------------------------------------- */
    
    /* ---------------------------------------------------- //

    For classes and functions the definition and declaration can also be in
    the same place.

    // ---------------------------------------------------- */

}



