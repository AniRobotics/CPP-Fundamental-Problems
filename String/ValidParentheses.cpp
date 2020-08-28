/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
*/

#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
  std::string s = "{[]}{}";
  std::stack<char> stk;

  for (char c : s) {
    std::cout << c << std::endl;
    if (c == '(' || c == '{' || c == '[') {
      stk.push(c);
    }
    else if (c == ')') {
      if (stk.top() != '(') {
        std::cout << "Invalid" << std::endl;
        break;
      }
      else {
        stk.pop();
      }
    }
    else if (c == '}') {
      if (stk.top() != '{') {
        std::cout << "Invalid" << std::endl;
        break;
      }
      else {
        stk.pop();
      }
    }
    else if (c == ']') {
      if (stk.top() != '[') {
        std::cout << "Invalid" << std::endl;
        break;
      }
      else {
        stk.pop();
      }
    }
  }

  if (!stk.empty()) {
    std::cout << "Invalid" << std::endl;
  }
  else {
    std::cout << "Valid" << std::endl;
  }

  return 0;
}

