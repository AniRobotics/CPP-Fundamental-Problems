/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::vector<std::string> VecStr;

std::string buildString(std::string s, int start, int end) {
  std::string res = "";
  for (int i = start; i <= end; i++) {
    res += s[i];
  }
  return res;
}

void getPalindrome(std::string str, int start, int end){
  while(start >= 0 && end < (int)str.length() && str[start] == str[end]) {
    VecStr.push_back(buildString(str, start, end));
    start--;
    end++;
  }
}

int main (int argc, char** argv) {
  std::string str = "aaa";

  for (int i = 0; i < (int)str.length(); i++) {
    getPalindrome(str, i, i);
    getPalindrome(str, i, i+1);
  }

  // Print all the palindromes
  for (auto s : VecStr) {
    std::cout << s << std::endl;
  }

  return 0;
}
