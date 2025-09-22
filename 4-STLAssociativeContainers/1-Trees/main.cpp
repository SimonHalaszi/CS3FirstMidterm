/*
STL SEQUENTIAL CONTAINERS

* trees, search trees and pairs

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <utility> // Where pair is from

int main() {

    // Tree section is more notes based

    // Pairs - Aggregate construct of two values,
    // possibly of different type

    // Two-- argument constructor
    std::pair<int, char> pic(1, 's');
    // No argument constructor
    std::pair<double, bool> p;
    // No one argument constructor
 
    // Can be copied and compared
    std::pair<int, char> pic2 = pic;

    if(pic2 == pic) {
        std::cout << "Yes pic2 and pic are equal" << std::endl;
    }

    // Can access individual elements with first and second
    std::cout << "pic2.first: " << pic2.first << std::endl;
    std::cout << "pic2.second: " << pic2.second << std::endl;

    // Can be made using. Say for insertings to map
    std::make_pair(1,4);

    // Also has intializer list
    std::pair<int, int> pii = {1, 4};
}