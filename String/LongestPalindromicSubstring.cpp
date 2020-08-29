/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

/*
Idea: We will scan the array using a single pointer. While scanning, we will
consider the pointer location as the middle of a valid palindromic substring
and we will expand the range.
*/

#include <iostream>

using namespace std;

int maxLenPalindrome(std::string s, int start, int end) {
  int maxLen = 0;
  while (start >= 0 && end < s.length() && s[start] == s[end]) {
    maxLen = end-start+1;
    start--;
    end++;
  }
  std::cout << "Local max len: " << maxLen << std::endl;
  return maxLen;
}

int main (int argc, char** argv) {
  std::string s = "babad";
  // std::string s = "cbbd";

  int maxLength = 0;

  for (int startInd = 0; startInd < s.length(); startInd++) {
    maxLength = max(maxLength, maxLenPalindrome(s, startInd, startInd));
    maxLength = max(maxLength, maxLenPalindrome(s, startInd, startInd+1));
  }

  std::cout << "Maximum length of substring: " << maxLength << std::endl;
  return 0;
}
