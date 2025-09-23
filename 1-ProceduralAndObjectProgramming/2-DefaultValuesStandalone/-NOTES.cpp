#include <iostream>

int main() {
    
    // ---------------------------------------------------- //

    // * default value for standalone function parameters
    
    /* 
    Default parameter value may be specified at function declaration
    or definition, but NOT both
        - convention - specify at declaration.

    Client has an option of specifying parameter or using default value
    
    Provides convenient alternative to overloading

    Only trailing parameters may have default values
    */

    // ---------------------------------------------------- //

    // Specify at declration, convention is to specify here
    void move(int from, int to = 0, int by = 1);

    /*
    Will cause errors because we are trying to define at both

    // Specfiy at definition, convention is to not specify here
    void move(int from, int to = 0, int by = 1) {
        return;
    }
    */

    /*
    Will cause errors because we are to make non-trailing parameters default

    // Specfiy at declaration, convention is to specify here
    void move(int from = 0, int to = 0, int by) {
        return;
    }
    */

    /*
    Can call move like this

    move(1)
    move(1, 2)
    move(1, 2, 3)

    But not this
    move()
    move(1, 2, 3, 4)
    
    Must have atleast as many arguments as non-default parameters
    Must have less arguments than parameters (duh)

    */

    // ---------------------------------------------------- //

}



