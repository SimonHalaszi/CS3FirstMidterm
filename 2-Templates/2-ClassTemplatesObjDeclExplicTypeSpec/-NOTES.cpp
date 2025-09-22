#include <iostream>

int main() {
    

    /* ---------------------------------------------------- //

    * class templates, object declaration, explicit type specification

    Deduction can be ambiguous
    
    double one = 3.5;
    int two = 5;
    showStuff(1, one, two); // int or double?

    Explicit type specification suppresses deduction and eliminates ambiguity

    showStuff<int>(1, one, two); // Will use type conversion to make one argument double

    // ---------------------------------------------------- */
    
    /* ---------------------------------------------------- //

    Parameterized class is generic class.
    
    Class definition is preceded by
        template<typename T>

    Example
        template<typename T>
        class MyClass{
            public:
                T methodInline() { return member_; }
                T methodOutside();
            private:
                T member_;
        };

    Member functions of a generic class are generic functions

    Member functions can be defined inline or outside

    For outside definition use scope resolution operator and template keyword

    template<typename T>
    MyClass<T>::methodOutside() { return member_; }

    // ---------------------------------------------------- */
    
    /* ---------------------------------------------------- //

    To declare an object of a generic class you have to explicitly
    specify type parameter (In version of c++ before c++17)

    MyClass<double> d;

    Methods are invoked the same as any other class

    d.methodOutside();

    Class or function template are not executable, compiler instantiates
    class templates when objects are declared, methods are instantiated 
    when invoked.
        - Put class templates in header files

    // ---------------------------------------------------- */
}



