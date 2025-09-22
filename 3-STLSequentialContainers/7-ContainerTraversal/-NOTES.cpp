#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * container traversal

    Container traversal - Visiting each element exactly once

    std::vector<int> v; // Make container

    for(
    std::vector<int>::iterator it = v.begin();
    it != v.end();
    ++it;
    ) {
        // Touches every element using half-open range from begin to end
    }

    Why not it < v.end()? Because for non-sequential containers this
    doesnt make sense. it < it2 could be true even though it actually
    does point to a later element. Why? because it is in an earlier 
    memory address. So for non-sequential containers iterator does
    not have defined less than. so it != v.end() is a universal
    way of traversing ANY container.

    Traversal with auto

    std::vector<int> v; // Make container

    for(
    auto it = v.begin();
    it != v.end();
    ++it;
    ) {
        // Touches every element using half-open range from begin to end
    }

    auto's type is deduced at compile time based on v.begin() return type

    Range-based for traversal

    std::vector<int> v; // Make container

    for(auto e : v) {
        // Touches every element using half-open range from begin to end
    }

    Notice auto is not of type iterator. That is of the type of v
    instantiation. So if this isnt auto& then this will make a copy
    of all elements in v as it traverses

    for(const auto& e : v) {
        // Touches every element using half-open range from begin to end
    }    

    A range-based for used for printing a container should look like
    the above loop

    Range-based for works on arrays, containers, intializer lists and
    any object that has begin() and end(). If using iterator type
    in begin() and end() this iterator must have defined prefix++
    and !=

    // ---------------------------------------------------- */
}


