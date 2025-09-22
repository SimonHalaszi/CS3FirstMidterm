#include <iostream>

int main() {

    /* ---------------------------------------------------- //

    // * local static variables

    Static variables are initialized only once and retain their
    value across function invocations. Scope is local, but memory 
    persist like a global variable.

    // ---------------------------------------------------- */

}
    void loginID() {
        static int logID = 0;
        int systemID = 12554423;

        std::cout << "LogID: " << logID 
                << " SystemID: " << systemID 
                << std::endl;

        ++logID;
    }


