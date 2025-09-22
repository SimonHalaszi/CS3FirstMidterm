/*
STL SEQUENTIAL CONTAINERS

* container adapters

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <stack>
#include <queue>
#include <iostream>

int main() {
    // Uses adapter pattern to modify a sequential underlying container
    // for a specific purpose by limiting interface.
    // NO iterators, NO indexing, FEW functions
    // size(), empty(), swap() are given

    // Cannot directly traverse container adapters (No tools to do so)

    // Stack. First in Last out / Last in First out
    // Uses deque, possibly vector or list
    std::stack<int> s;

    s.push(10); // 10
    s.push(40); // 40 10
    s.push(50); // 50 40 10
    s.pop();        // no return of variable just pops it off   // 40 10
    std::cout << "s.top(); " << s.top() << std::endl;  // top to get top value // 40

    // Queue. First in First out / Last in Last out
    // Uses deque, possible list
    // NOT vector. no push_front() for vector
    std::queue<int> q;

    q.push(10); // 10
    q.push(40); // 10 40
    q.push(50); // 10 40 50
    q.pop();        // no return of variable just pops it off   // 40 50
    std::cout << "q.front(); " << q.front() << std::endl;  // front value // 40
    std::cout << "q.back(); " << q.back() << std::endl;  // back value // 50

    // Priority Queue. Highest Priority First Out / Lowest Priority Last Out
    // Uses vector, possible deque
    std::priority_queue<int> pq;
    pq.push(10); // 10
    pq.push(40); // 40 10
    pq.push(50); // 50 40 10
    pq.push(20); // 50 40 20 10
    pq.pop();        // no return of variable just pops it off   // 40 20 10
    std::cout << "q.top(); " << pq.top() << std::endl;  // highest priority value // 40  
}