/*
STL ASSOCIATIVE CONTAINERS

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

  // A map can be const and a map can map to constant elements
  // key is always const
  
  // Cant do
  // std::map<int, char>::iterator mapicb = mapic.begin();
  // mapicb->first = 2;

  // Inserting in maps

  // Can use indexing overload to change data at key and add pairs

  // Key 2 isnt used yet so will create a pair of {2, 'a'}
  mapic[2] = 'a';

  std::cout << "mapic: " << std::endl;
  for(const auto& e : mapic) {
    std::cout << "Key: " << e.first
              << " Data Value: " << e.second << std::endl;    
  }   

  // This type of insert is considered "unsafe", because it will
  // overwrite old data if they key does exist
  // Changes 2 data to 'b'
  mapic[2] = 'b';

  std::cout << "mapic: " << std::endl;
  for(const auto& e : mapic) {
    std::cout << "Key: " << e.first
              << " Data Value: " << e.second << std::endl;    
  }  

  // A "safe" insert function exist
  // Return type is a pair of <correct_iterator, bool>


  // If inserted pair is using an already occupied key it does not overwrite old data.
  // If inserted pair is using an already occupied key the bool will be false
  // If inserted pair is using an already occupied key the iterator will be to existing element
  std::pair<std::map<int, char>::iterator, bool> pairitb = mapic.insert(std::make_pair(2, 'c')); // 2 will still be to 'b'
  if(pairitb.second) {  // wont print
    std::cout << "insert happended" << std::endl;
  }

  // If inserted pair is not using an already occupied key it makes new map entry
  // If inserted pair is not using an already occupied key the bool will be true
  // If inserted pair is not using an already occupied key the iterator will be to created element
  pairitb = mapic.insert(std::make_pair(1, 'c')); // New entry
  if(pairitb.second) {  // will print
    std::cout << "insert happended" << std::endl;
  }  

  std::cout << "mapic: " << std::endl;
  for(const auto& e : mapic) {
    std::cout << "Key: " << e.first
              << " Data Value: " << e.second << std::endl;    
  }    

  // Can insert initalizer list 
  pairitb = mapic.insert({12, 'j'});

  int i = 13; char c = 'd';

  pairitb = mapic.insert({i, c});

  std::cout << "mapic: " << std::endl;
  for(const auto& e : mapic) {
    std::cout << "Key: " << e.first
              << " Data Value: " << e.second << std::endl;    
  }      

  // Can use a "hint" iterator for inserts at optimal position
  // This can save time but if the hint is incorrect it will be ignored 

  // For inserting the largest key (16), hint should be end()
  // since the new element will be inserted at the end
  std::map<int, char>::iterator itr = mapic.end();
  // Good hint: end() for largest key insertion
  // Returns iterator not iterator, bool pair
  itr = mapic.insert(itr, std::make_pair(16, 'e')); // This hint IS used effectively

  std::cout << "mapic: " << std::endl;
  for(const auto& e : mapic) {
    std::cout << "Key: " << e.first
              << " Data Value: " << e.second << std::endl;    
  }    

  // Can range insert
  std::map<int, char> newmapic;
  newmapic.insert(mapic.lower_bound(1), mapic.upper_bound(10));

  std::cout << "newmapic: " << std::endl;
  for(const auto& e : newmapic) {
    std::cout << "Key: " << e.first
              << " Data Value: " << e.second << std::endl;    
  }      

  // Erase functions same as other containers

  // itr goes to element past where itr was, should be end()?
  itr = mapic.erase(itr);

  if(itr == mapic.end()) {
    std::cout << "itr erased last element" << std::endl;
  }

  std::cout << "mapic: " << std::endl;
  for(const auto& e : mapic) {
    std::cout << "Key: " << e.first
              << " Data Value: " << e.second << std::endl;    
  }   

  // Or range erase

  // itr goes to element just out of this range so 13
  itr = mapic.erase(mapic.lower_bound(3), mapic.upper_bound(12)); // 10 to 13 half open range
  
  std::cout << "mapic: " << std::endl;
  for(const auto& e : mapic) {
    std::cout << "Key: " << e.first
              << " Data Value: " << e.second << std::endl;    
  }     

  // Or can erase by key, returns number of nodes erased (relevant to multimap)
  int num = mapic.erase(1);
  if(num == 1) {
    std::cout << "erased one element with key 1" << std::endl;
  }


}