#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

int main (int argc, char** argv) {
  std::unordered_map<std::string, int> UMap;

  // Type-1: element insertion
  UMap["NumCuisine"] = 1;
  UMap["NumDress"] = 6;

  // Type-2: element insertion
  UMap.insert(std::make_pair<std::string, int> ("NumCitizen",3));

  // Iterating over an unordered_map object
  for (auto it = UMap.begin(); it != UMap.end(); it++) {
    std::cout << "Key: " << it->first << "; Value: " << it->second << std::endl;
  }

  // Look for a key in an unordered_map object
  std::string find_key = "NumCitizen";
  auto find_itr = UMap.find(find_key);
  if (find_itr != UMap.end()) {
    std::cout << "Key named " << find_key << " exists" << std::endl;
    std::cout << "It's value is: " << find_itr->second << std::endl;
  }

  // Erase an element after finding by searching over the keys
  auto it = UMap.begin();
  while (it != UMap.end()) {
    if (it->first == find_key) {
      it = UMap.erase(it);
    }
    else {
      it++;
    }
  }

  // Check if the element with find_key as key value has been erase
  for (auto it = UMap.begin(); it != UMap.end(); it++) {
    std::cout << "Key: " << it->first << "; Value: " << it->second << std::endl;
  }

  return 0;
}
