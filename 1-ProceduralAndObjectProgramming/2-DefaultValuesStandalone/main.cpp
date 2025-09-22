/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* default value for standalone function parameters

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>

int addInts(int intOne, int intTwo = 0, int intThree = 0) {
    return (intOne + intTwo + intThree);
}

void printInts(int intOne = 0, int intTwo = 0, int intThree = 0) {
    std::cout << intOne << " " << intTwo << " " << intThree << std::endl;
}

/*
Cant do these two examples. Default parameters must be trailing.

int someFunc(int intOne = 0, int intTwo, int intThree = 0);
int someFunc(int intOne = 0, int intTwo, int intThree);

*/

int main() {
    int a = 100;
    int b = 200;
    int c = 300;

    std::cout << addInts(a, b, c) << std::endl;     // 600
    std::cout << addInts(b, c) << std::endl;        // 500
    std::cout << addInts(c) << std::endl;           // 300
    // std::cout << addInts() << std::endl;         // Cant do

    printInts(a, b, c);                             // 100 200 300
    printInts(a, b);                                // 100 200 0
    printInts(c);                                   // 100 0
    printInts();                                    // 0 0 0
    
}