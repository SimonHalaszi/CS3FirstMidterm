#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * trees, search trees and pairs

    Tree - A graph with no cycles
    Rooted Tree - A tree with a single distinguished node - Root

    Given a node N
        - Ancestors - Nodes on path from N to root
        - Descendants - Nodes whose ancestor is N
        - Subtree - All descendants of a node
        - Parent - Closest Ancestor to N
        - Children - Closest Descendants to N
        - Leaf - Node with no children.
        - Root - Node with no parents.
        - Height - Length of longest path to a leaf
        - Depth - Length of path to the root from N

    Binary tree - Each parent has at most two children
    Search Tree - Nodes store keys.
    Sorted Binary Tree - Key in node is greater than.
    keys in left subtree and less than keys right subtree.
    Heap data structure uses this. priority_queue implements.

    Search Trees

    Balanced search tree - constraint on differences in subtrees height
    Self-balancing search tree - Maintains balance under insert/delete operations
    Red-Black tree - Self-balanced binary search tree with these properties
        - Every node is either red or black
        - The root is always black
        - All null nodes (NIL nodes) are considered black
        - A red node does not have a red child (no adjacent red nodes)
        - Every path from a given node to any of its leaf nodes goes through
        the same number of black nodes (black-height property)
        - Guarantees O(log(n))
            - Lookups
            - Insertions/Deletions
        - New nodes are initially inserted as red to preserve black-height
        - Insertions may rebalance the tree; rotations and recoloring can
        affect every node on the path to the insertion point
        - Black-height (and thus tree height) grows slowly - roughly when
        the capacity at current black-height is exhausted

    Pairs

    - Aggregate values of two, possible different, types
    - Used in associative containers
    - Defined in <utility>
    - May use a two-argument constructor or no argument constructor
        - No single argument constructor
    - May copy and compare
    - May access individual elements with 'first' and 'second'
    - May create with std::make_pair(arg1, arg2) function that 
    returns a pair composed of arg1 and arg2 // Type of pair
    gets deduced by arguments  

    // ---------------------------------------------------- */
}


