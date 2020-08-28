/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char** argv) {
  // // Example 1
  // std::string s = "anagram";
  // std::string t = "nagaram";

  // Example 2
  std::string s = "cat";
  std::string t = "rat";

  if (s.size() != t.size()) {
    std::cout << "The two strings are not anagram" << std::endl;
    return 0;
  }

  std::unordered_map<char,int> umap;
  for (int i = 0; i < s.size(); i++) {
    umap[s[i]] += 1;
  }

  for (int i = 0; i < t.size(); i++) {
    auto tempItr = umap.find(t[i]);
    if (tempItr != umap.end()) {
      umap[t[i]]--;
      if (umap[t[i]] == 0) {
        umap.erase(tempItr);
      }
    }
    else {
      umap[t[i]] = 1;
    }
  }

  if (!umap.empty()) {
    std::cout << "Size of the hash map: " << umap.size() << std::endl;
    std::cout << "The two strings are not anagram of each other" << std::endl;
  }
  else {
    std::cout << "The two strings are anagram of each other" << std::endl;
  }

  return 0;
}
