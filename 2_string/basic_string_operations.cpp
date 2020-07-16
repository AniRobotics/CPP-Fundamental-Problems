#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char** argv) {
  std::string name = "anirban";

  // Iterating over a string object to create (char, int) pair.
  std::vector<pair<char,int>> name_asciis;
  for (size_t i = 0; i < name.size(); i++) {
    name_asciis.push_back({name[i], int(name[i])});
  }

  // Iterate over the name_asciis variable
  for (auto i = name_asciis.begin(); i != name_asciis.end(); i++) {
    std::cout << i->first << " -> ";
    std::cout << "ASCII value -> " << i->second << std::endl;
  }
  std::cout << "--------------------" << std::endl;

  // Use of std::to_string(.) method to get char from
  //integer representing ASCII value.
  for (auto i = name_asciis.begin(); i != name_asciis.end(); i++) {
    std::cout << "ASCII value -> " << i->second << " - ";
    std::cout << "char -> " << (char)i->second << std::endl;
  }
  std::cout << "--------------------" << std::endl;

  return 0;
}
