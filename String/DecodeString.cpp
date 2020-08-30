/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].



Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
*/

/*
Useful built in methods: isalpha(), isdigit()
*/

#include <iostream>
#include <stack>

using namespace std;

int main (int argc, char** argv) {
  // std::string s = "3[a]2[bc]"; // example 1
  std::string s = "3[a2[c]]";
  std::stack<std::string> stk_s;
  std::stack<int> stk_i;

  int i = 0;
  int num = 0;
  std::string str = "";
  std::string totalStr = "";

  while (i < (int)s.length()) {
    if (isdigit(s[i])) {
      while (isdigit(s[i])){
        num = 10*num + (s[i] - '0');
        i++;
      }
      stk_i.push(num);
      num = 0; // reset num
    }
    else if (isalpha(s[i])) {
      while (isalpha(s[i])) {
        str += s[i];
        i++;
      }
      stk_s.push(str);
      str = ""; // reset str
    }
    else if (s[i] == '[') {
      stk_s.push("[");
      i++;
    }
    else { // ']' case
      while(stk_s.top() != "[") {
        totalStr = stk_s.top() + totalStr;
        std::string tempStr = totalStr;
        for (int i = 1; i < stk_i.top(); i++) {
          totalStr = totalStr + tempStr;
        }
        stk_s.pop();
        stk_i.pop();
      }
      stk_s.pop();
      i++;
    }
  }

  std::cout << totalStr << std::endl;

  return 0;
}
