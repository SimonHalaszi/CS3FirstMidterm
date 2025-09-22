/*
STL SEQUENTIAL CONTAINERS

* map, declaring, traversing, element lookup
  element inserting, range inserting
  element erasing

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <map>
#include <utility>
#include <iostream>

int main() {
  // Map with integer keys to char values
  std::map<int, char> mapic;

  // Implemented using pairs
  mapic.insert(std::make_pair(1, 'c'));

  std::pair<int, char> pic = {4, 'f'};

  mapic.insert(pic);

  {
    // Can use move
    std::pair<int, char> xpic = {10, '@'};

    mapic.insert(std::move(xpic));
  }

  // Can iterator over map container in order of key values
    std::cout << "mapic: " << std::endl;
  for(std::map<int, char>::iterator it = mapic.begin();
      it != mapic.end();
      ++it
  ) {
    std::cout << "Key: " << it->first 
              << " Data Value: " << it->second << std::endl;
  }

  // Or save some typing and using range-based for
  std::cout << "mapic: " << std::endl;
  for(const auto& e : mapic) {
    std::cout << "Key: " << e.first
              << " Data Value: " << e.second << std::endl;    
  }

  // -- Lookup --

  // Indexing takes a key and returns its value
  std::cout << "mapic[10]: " << mapic[10] << std::endl;
  // If you put it wrong key while accessing it usings
  // data values default constructor

  // find() function returns iterator to pair given a key
  std::map<int, char>::iterator it = mapic.find(10);
  std::cout << "std::map<int, char>::iterator it = mapic.find(10);" << std::endl;
  std::cout << "Key: " << it->first 
            << " Data Value: " << it->second << std::endl;  

  // If key does not refer to any element returns end()
  it = mapic.find(100);
  if(it == mapic.end()) {
    std::cout << "Yeah that key doesnt exist" << std::endl;
  }

  // Make a half open range
  std::map<int, char>::iterator hors = mapic.lower_bound(1);
  std::map<int, char>::iterator hore = mapic.upper_bound(4);

  // Will get rid of elements starting at key 1 to key 4
  // Still half open range because upper_bound(4) actually
  // returns the next greatest key of 4 not 4 ( if it exist )
  mapic.erase(hors, hore);
  std::cout << "mapic: " << std::endl;
  for(const auto& e : mapic) {
    std::cout << "Key: " << e.first
              << " Data Value: " << e.second << std::endl;    
  }
}