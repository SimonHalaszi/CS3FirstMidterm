/*
PROCEDURAL AND OBJECT-BASED PROGRAMMING

* local static variables

c++ main.cpp 
./a.out > output.txt
rm ./a.out

*/

#include <iostream>

void loginID() {
    // Static variable only gets intialized once.
    // Scope is local but memory persist like global variable
    static int logID = 0;
    int systemID = 12554423;

    std::cout << "LogID: " << logID 
              << " SystemID: " << systemID 
              << std::endl;

    ++logID;
}

int main() {
    std::cout << "Running loginID function 6 times. LogID is static and gets incremeted each time." << std::endl;
    loginID();  // LogID: 0 SystemID: 12554423
    loginID();  // LogID: 1 SystemID: 12554423
    loginID();  // LogID: 2 SystemID: 12554423
    loginID();  // LogID: 3 SystemID: 12554423
    loginID();  // LogID: 4 SystemID: 12554423
    loginID();  // LogID: 5 SystemID: 12554423
    std::cout << std::endl;

    // Note looping variables arent staic varibles. Their scope isnt the loop body. They are declared in a higher scope
    // in the loop header.
    std::cout << "Running for loop with looping variable intialized to 0 and static int intialized to 0." << std::endl;
    for(int i = 0; i < 10; ++i) {
        static int staticI = 0;
        std::cout << "i = " << i << " = staticI = " << staticI << std::endl;
        ++staticI;
    }
}