/*
TEMPLATES

* friends of templated class, general vs. specific templates

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>

// Forward declaration needed

// Telling compiler a templated class TemplateClass will be defined
template<typename X>
class TemplateClass;

// Telling compiler a templated function specificFriend will be defined
// And that it will use TemplateClass of the templated type.
template<typename X>
bool specificFriend(const TemplateClass<X>&, const TemplateClass<X>&);

// Same thing
template<typename X>
bool operator==(const TemplateClass<X>&, const TemplateClass<X>&);

// Same thing
template<typename X>
std::ostream& operator<<(std::ostream&, const TemplateClass<X>&);

template<typename T>
class TemplateClass{
    public:
        // Templated methods
        TemplateClass(T val = T()) : member_(val) {}
        const T& getMemberRef() const { return member_; }
        void setMember(const T& val) { member_ = val; }
        void print() const { std::cout << member_; }

        /*
        
        genericFriend exist for any instantiation of TemplateClass. No guarantee
        that it is friend of the same type as the object that calls it.
        Can use private members of all instantiations. BAD!

        */
        template<typename U>
        friend bool genericFriend(const TemplateClass<U>&, const TemplateClass<U>&);

        /*
        
        Telling compiler that specificFriend is actually a friend to TemplateClass.
        The "specificFriend<T>" is explicitly telling compiler that this function
        will be of the same type as TemplateClass.      
        
        */
        friend bool specificFriend<T>(const TemplateClass<T>&, const TemplateClass<T>&);

        // More advanced friend. Overloading equality
        friend bool operator==<T>(const TemplateClass<T>&, const TemplateClass<T>&);
        // More advanced friend. Overloading insertion
        friend std::ostream& operator<< <T>(std::ostream&, const TemplateClass<T>&);

    private:
        // Templated member variable
        T member_;
};

TemplateClass<double> victimDouble(3.14);

// Defining genericFriend. Template here just lets the compiler know that its templated.
template<typename U>
bool genericFriend(const TemplateClass<U>& lhs, const TemplateClass<U>& rhs) {
    // I can do this even when instantiation isn't double.
    // That is a BAD thing.
    victimDouble.member_ = 67.67;
    return lhs.member_ == rhs.member_;
}

// Finally defining specificFriend. Template here just lets the compiler know that its templated.
template<typename T>
bool specificFriend(const TemplateClass<T>& lhs, const TemplateClass<T>& rhs) {
    // victimDouble.member_ = 420.420; // Wont even compile if we try this
    return lhs.member_ == rhs.member_;
}

template<typename T>
bool operator==(const TemplateClass<T>& lhs, const TemplateClass<T>& rhs) {
    return lhs.member_ == rhs.member_;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const TemplateClass<T>& rhs) {
    out << rhs.member_;
    return out;
}

int main() {
    TemplateClass<int> intObjOne(20);
    std::cout << "intObjOne: " << intObjOne << std::endl;
    TemplateClass<int> intObjTwo(20);
    std::cout << "intObjTwo: " << intObjTwo << std::endl;
    std::cout << "victimDouble: " << victimDouble << std::endl;

    if(genericFriend(intObjOne, intObjTwo)) {
        std::cout << "intObjOne == intObjTwo, according to genericFriend" << std::endl;
    }

    std::cout << "But the genericFriend of supposed int instantiation used victimDouble private variables" << std::endl;
    std::cout << "This shouldnt happen victimDouble isnt typed int!" << std::endl;
    std::cout << "victimDouble: " << victimDouble << std::endl;

    if(specificFriend(intObjOne, intObjTwo)) {
        std::cout << "intObjOne == intObjTwo, according to specificFriend" << std::endl;
    }

    std::cout << "specificFriend couldnt touch victimDouble." << std::endl;

    if(intObjOne == intObjTwo) {
        std::cout << "intObjOne == intObjTwo, according to overloaded equality" << std::endl;
    }

    std::cout << "These friends work perfectly with nested templates!." << std::endl;

    TemplateClass<TemplateClass<int>> nestedOne(TemplateClass(20));
    std::cout << "nestedOne: " << nestedOne << std::endl;

    TemplateClass<TemplateClass<int>> nestedTwo(TemplateClass(20));
    std::cout << "nestedTwo: " << nestedTwo << std::endl;

    if(nestedOne == nestedTwo) {
        std::cout << "nestedOne == nestedTwo, according to overloaded equality" << std::endl;
    }    
}