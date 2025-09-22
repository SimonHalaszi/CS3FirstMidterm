#include <iostream>

int main() {
    
    // CONFUSING TAKE EXTRA LOOK

    // * friends of templated class, general vs. specific templates

    /* ---------------------------------------------------- //

    Two ways:
    1. General Template
        template<typename T>
        class MyClass{
            public:
                template<typename U>
                friend bool equal(const MyClass<U>&, const MyClass<U>&);
            private:
                T member_;
        };

        template<typename U>
        bool equal(const MyClass<U>& lhs, const MyClass<U>& rhs) {
            return lhs.member_ == rhs.member_;
        }

    Problem: The templated friend is a friend to all instantiations, 
    potentially a security concern: Malicious programmer may redefine
    friend to access other instantiations.

    This is because typename U has no guarantee that it is of same type
    as typename T. It's just saying that equal is templated and will
    work with generic typing. But that 'working' extends to literally
    any type. Not just of type T.

    2. Specific Template
        // Declaring a templated class MyClass
        template<typename X>
        class MyClass;

        // Declaring a templated equal function
        template<typename X>
        bool equal(const MyClass<X>&, const MyClass<X>&);

        template<typename T>
        class MyClass{
            public:
                // Telling compiler that standalone function equal is a friend
                // to templated class MyClass. The equal<T> is also telling compiler
                // that equal is templated to the SAME TYPE as object calling it
                friend bool equal<T>(const MyClass<T>&, const MyClass<T>&);
            private:
                T member_;
        };

        // Finally defining equal
        template<typename T>
        bool equal(const MyClass<T>& lhs, const MyClass<T>& rhs) {
            return lhs.member_ == rhs.member_;
        }   

    Note: The template angle brackets in friend declaration inside the class.
    Needed to denote template is the same as object. Also needed to denote
    this is a templated function.

    // ---------------------------------------------------- */
}



