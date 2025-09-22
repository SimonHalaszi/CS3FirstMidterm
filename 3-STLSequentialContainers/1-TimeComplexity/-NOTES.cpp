#include <iostream>
int main() {
    
    /* ---------------------------------------------------- //
    
    * time complexity, amortized time complexity

    - Estimates efficiency of algorithm
    - Measured in the number of elementary operations performed
    by algorithm
    - Estimated in worst case 
    - Relates to size of input n
    - Common complexities
        - constant O(1) [ Independent of input size ]
        - logarithmic O(log(n))
        - linear O(n)
        - quasilinear O(nlog(n))
        - quadratic O(n^2)
        - polynomial O(n^3)...
        - exponential O(2^n)

        And theres worse but if your algorithm is worse you should
        probably go back to the drawing board.

        - factorial O(n!)...   
        
    What is the complexity of...
        - Finding smallest number in sorted array? unsorted array?
            sorted array: O(1)      -> array[0]
            unsorted array: O(N)    -> for loop
        - Finding a practicular number in a sorted array?
            O(log(n))               -> binary search
        - Sorting an array?
            O(nlog(n))              -> merge sort
        - Sorting an array with insertion or bubble sort?
            O(n^2)                  -> nested for loops

    Amortized Complexity
        - (Worst Case) Complexity per data item or operation
        - Think as you run a certain operaiton a lot of time, what
        will the eventual complexity be?

        Example: vector.push_back()
        vector buffer gets doubled everytime client pushes to a full one
            - When buffer not full: O(1)
            - When buffer full: O(n) [ All data needs copied to bigger buffer ]
            - Amortized complexity with a big n: 
                (nO(1)+O(n))/(n+1) = ~2n/n = 2 = ~O(1)
            ( As we keep pushing more items the O(n) operation gets more and more rare
            so for a very large n that bulk of operations will be O(1) )

        While the amortized complexity is O(1) for vector push this
        can be seen as optimistic. For a vector that gets pushed to
        only 5 times the complexity is actually linear [ O(2n) < tc ].

    // ---------------------------------------------------- */

}


