#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int main (int argc, char** argv) {
  // Create a map of characters and their ASCII values
  std::unordered_map<char,int> CharAscii;

  int AsciiVals;
  for (int i = 0; i != 26; i++) {
    AsciiVals = (int)'a'+i;
    CharAscii[(char)AsciiVals] = AsciiVals;
  }

  // Iterate over the unordered_map object
  for (auto i = CharAscii.begin(); i != CharAscii.end(); i++) {
    std::cout << "Key: " << i->first << " Value: " << i->second << std::endl;
  }

  // Use a Priority Queue to arrange the map based on the ascii values
  auto cmp = [](pair<char,int> left, pair<char,int> right) {return left.second > right.second;};
  std::priority_queue<std::pair<char,int>,std::vector<pair<char,int>>,decltype(cmp)> pq(cmp);

  auto it = CharAscii.begin();
  while (it != CharAscii.end()) {
    pq.push(std::make_pair(it->first,it->second));
    it++;
  }

  while (!pq.empty()) {
    auto element = pq.top();
    pq.pop();
    std::cout << element.first << " : " << element.second << std::endl;
    // std::cout << pq << std::endl;
  }

  return 0;
}
