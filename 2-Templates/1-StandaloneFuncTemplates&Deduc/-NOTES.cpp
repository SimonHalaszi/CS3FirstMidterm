#include <iostream>

int main() {
    

    /* ---------------------------------------------------- //

    * standalone function templates, type parameter deduction

    function head/prototype are preceded by
        template<typename typeParameterName>

    Style convention is to put this on preceeding line
        template<typename T>
        void func(T var);

    Type parameter may be passed by reference, returned and be const

    Generic type functions are called normally

    Templates are not executable code.
        - Compiler generates executable code when it sees function
        invocation. This generated code is called the template
        instantiation
            - Compiler deduces the type of template parameter
            by the type of the arguments passed in
            - Parameterized function is generic function
        - Cannot be compiled seperately
        - Should be placed in header files

    // ---------------------------------------------------- */

}



