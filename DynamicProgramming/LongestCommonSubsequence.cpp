/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.



If there is no common subsequence, return 0.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/

#include <iostream>

using namespace std;

int main (int argc, char** argv) {
  std::string text1 = "abcde";
  std::string text2 = "ace";

  // Initialize a DP array with length as text1.length() and
  // width same as text2.length().
  int dpArray[text2.length()+1][text1.length()+1];

  // Initialize all the cells of the 2D array to 0
  for (size_t i = 0; i <= text2.length(); i++) {
    for (size_t j = 0; j <= text1.length(); j++) {
      dpArray[i][j] = 0;
    }
  }

  // Prepare the dynamic programming table (bottom up approach)
  for (size_t i = 1; i <= text2.length(); i++) {
    for (size_t j = 1; j <= text1.length(); j++) {
      if (text2[i-1] == text1[j-1]) {
        dpArray[i][j] = 1 + dpArray[i-1][j-1];
      }
      else {
        dpArray[i][j] = max(dpArray[i-1][j], dpArray[i][j-1]);
      }
      std::cout << "[" << i << "," << j << "] = " << dpArray[i][j] << std::endl;
    }
  }

  std::cout << "Max Length of Common Substring: "
  << dpArray[text2.length()][text1.length()] << std::endl;

  return 0;
}
