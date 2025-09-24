#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * container update functions, iterator invalidation, loop modification idiom

    // ---------------------------------------------------- //

    insert() - for all sequential containers other than std::array and std::forward_list

    itr = insert(position, value);  // value insert
    itr = insert(position, repeats, value); // fill insert
    itr = insert(position, from, to); // will insert a range of elements to position

    forward_list has insert_after same overloads just will insert after position

    We did not study forward_list in class to heavily so ignoring it here

    Returns iterator to first of the inserted elements.
    
    // ---------------------------------------------------- //

    erase() - for all sequential containers other than std::array and std::forward_list

    itr =  erase(position);
    itr =  erase(from, to);

    forward_list has erase_after same overloads just will erase after position

    We did not study forward_list in class to heavily so ignoring it here

    Returns iterator to element after ones erased

    // ---------------------------------------------------- //

    assign() - for all sequential containers

    assign(from, to); // Replaces contents of callee with copies of contents
                         of inputted range, which could be of different container
                         type. Also works with intializer list.
    assign({1, 2, 3});

    Void function
                         
    // ---------------------------------------------------- //     
    
    For sequential containers update operations could possibley invalidate
    iterators in the containers, due to potential storage reallocation
        vector: all iterators past the point of insertion unless capacity reached
        deque: all iterators unless insertion is at front/back
        list: iterators unaffected

    erase() - returns iterator to next element past erased
    insert() - returns iterator to the first of the inserted elements

    These returned iterators can be used to keep iterator validated without extra
    lines of code, and while keeping it in the desired spot.

    // ---------------------------------------------------- //     
    
    Good rule of thumb, if a funciton takes an iterator from the object calling it,
    then this function will return a validated iterator. For sequeuntial containers.

    // ---------------------------------------------------- //     

    Loop-modification idiom
    
    Way of modifying idiom as you traverse it    

    for(auto it = v.begin(); it != v.end();) {
        if(*it == 0) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }    

    // ---------------------------------------------------- //     

    Iterator Errors

    - Iterators are as (un)safe as pointers
    - However, some errors are iterator specific
        - Whats wrong with this code?
            vector<int> v;
            auto it = v.end();
            *it = 20;

            Dereferncing end() iterator is undefined behaviour
            like nullptr dereference

        - Whats wrong with this code?
            vector<int> one(10), two(10);
            for(auto it = one.begin(); it != two.end(); ++it) {
                std::cout << *it;
            }

            This will loop an unpredictable amount of times. two.end()
            has no relation to one.begin()

    // ---------------------------------------------------- */
}


