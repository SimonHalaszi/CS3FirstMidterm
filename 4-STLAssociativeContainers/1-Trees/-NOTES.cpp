#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * trees, search trees and pairs

    Trees:
        tree - a graph with no cycles
        rooted tree - a tree with a single distinguished node - root

    Given a node N
        - ancestors - nodes on path from N to root
        - descendants - nodes whose ancestor is N
        - subtree - all descendants of note N, tree that would
        be made if N was root.
        - parent - closest ancestor
        - child - closest descendant
        - leaf - node with no children, root - node with no parents
        - height - length of longest path to leaf
        - depth - length of path N to the root

    Binary tree - Each parent has at most two children
    Search tree - Nodes store keys
    Sorted binary tree - Key in node is greater than keys
    in left subtree and less than keys in right subtree. Heap
    data structure used in priority_queue uses this

    Balanced search tree - Constraint on differences in
    subtrees height
    Self-balancing search tree - Maintains balance under insert/
    delete operations.
    Red-black tree - Self-balanced binary search tree with these
    properties
        - root and leaves are black
        - insertion - adding node and coloring it red
        - red node's children are always black, hench the name
        - depth of one leaf is no more than twice the depth
        of another
        - guarantees O(log(n))
            - lookups
            - insetions/deletions
    
        Structure of tree depends on inserted order. Sortedness
        of red-black tree is not clearly apparent to an
        unknowledgable progammer. Given an element N say
        N will be inserted in a fashion where if it is less
        than already existing child or it will go the left.
        And if N is greater than already existing it will go
        to the right.


    // ---------------------------------------------------- */
}


