/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <set>

using namespace std;

int main(int argc, char** argv) {
  std::string s = "abcabcbb";
  std::set<char> uniqSet;

  int count = 0;
  int maxLength = 0;
  for (size_t i = 0; i < s.size(); i++) {
    // std::cout << *it << std::endl;
    auto findItr = uniqSet.find(s[i]);
    if (findItr == uniqSet.end()) {
      std::cout << s[i] << " : added" << std::endl;
      uniqSet.insert(s[i]);
    }
    else {
      while (uniqSet.find(s[i]) != uniqSet.end()) {
        std::cout << s[count] << " : will be deleted" << std::endl;
        auto tempItr = uniqSet.find(s[count++]);
        uniqSet.erase(tempItr);
      }
      std::cout << s[i] << " : added" << std::endl;
      uniqSet.insert(s[i]);
    }
    maxLength = max(maxLength,(int)uniqSet.size());
  }
  std::cout << "----------------------------" << std::endl;
  std::cout << "Max length of substring: " << maxLength << std::endl;
  std::cout << "----------------------------" << std::endl;
  
  // for (auto it = uniqSet.begin(); it != uniqSet.end(); it++) {
  //   std::cout << *it << endl;
  // }

  return 0;
}
