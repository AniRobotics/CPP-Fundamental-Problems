/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/

/*
The idea is to sort each string, so that all the anagrams looks the same.
We use each of these sorted strings as key and store the corresponding
actual strings as values.
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <unordered_map>

int main (int argc, char** argv) {
  std::vector<std::string> vec = {"eat","tea","tan","ate","nat","bat"};
  std::unordered_map<std::string,std::vector<std::string>> umap;

  for (auto str : vec) {
    std::vector<char> charArray;
    for (char c : str) {
      charArray.push_back(c);
      std::sort(charArray.begin(),charArray.end());
    }
    std::string sortedStr = "";
    for (char c : charArray) {
      sortedStr += c;
    }
    // if (umap.find(sortedStr) != umap.end()) {
      umap[sortedStr].push_back(str);
    // }

  }

  // Print the Hash Map
  for (auto it = umap.begin(); it != umap.end(); it++) {
    std::cout << "Key: " << it->first << std::endl;
    std::cout << "Value: ";
    for (std::string c : it->second) {
      std::cout << c << ", ";
    }
    std::cout << "\n--------------------" << std::endl;
  }

  return 0;
}
