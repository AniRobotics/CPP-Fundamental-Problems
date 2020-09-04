/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

bool wrdBrk(std::string s, std::set<std::string>& setDict) {
  if (s == "") {
    // we have done matching all the previous characters
    return true;
  }
  for (int i = 0; i <= s.length(); i++) {
    if (setDict.find(s.substr(0,i)) != setDict.end() && wrdBrk(s.substr(i,s.length()), setDict)) {
      return true;
    }
  }
  return false; // if reached this point, no match found
}

int main (int argc, char** argv) {
  std::string s = "leetcode";
  std::vector<std::string> wordDict = {"leet", "code"};

  // DP bottom up approach
  std::set<std::string> setDict;
  for (auto w : wordDict) {
    setDict.insert(w);
  }

  // // Get familize with substr() method
  // for (int i = 1; i <= s.length(); i++) {
  //   // std::cout << s.substr(0, i) << " i = " << i << std::endl;
  //   if (setDict.find(s.substr(0,i)) != setDict.end()) {
  //     std::cout << s.substr(0,i) << std::endl;
  //   }
  // }

  if (wrdBrk(s, setDict)) {
    std::cout << "true" << std::endl;
  }
  else {
    std::cout << "false" << std::endl;
  }

  return 0;
}
