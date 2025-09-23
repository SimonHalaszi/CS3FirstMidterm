#include <iostream>
int main() {

    /* ---------------------------------------------------- //

    * hash tables

    Hash Tables

    - An array of buckets where elements are stored
    - Hash function translates (hashes) key to bucket index
    - Collision - When different keys hash to same bucket
        - Usually resolved through chaining (linked list in each bucket)
    - Implements amortized O(1) element lookup/insertion/deletion
        - Amortized O(1) because hash table does dynamically expand
        when it gets close to full
    - With no collision lookup/insertion/deletion is O(1)
    - With collision lookup/insertion/deletion is O(n) [ Need to go through 
    linked list and compare keys to find right one ]

    Why Hash Tables for Unordered Containers?

    Performance Trade-off:
    - Trees (map/set): O(log n) but elements stay sorted
    - Hash Tables (unordered_map/unordered_set): O(1) average but no ordering

    Key Benefits:
    - Much faster lookups when you don't need sorted order
    - Constant time insertion/deletion on average
    - Perfect when you just need "does this key exist?" quickly

    Why "Unordered"?
    - Hash function scrambles key values to distribute evenly
    - No relationship between key values and their bucket positions
    - Keys 1, 2, 3 might end up in buckets 5, 2, 8 (random-looking)
    - Iteration order has nothing to do with key order

    When to Use:
    - Use hash tables when you need speed and don't care about order
    - Use trees when you need sorted iteration or range queries

    // ---------------------------------------------------- */
}


