#include <iostream>
#include <vector>

using namespace std;

bool CheckPalindrome(std::string given_str) {
  int left_idx = 0;
  int right_idx = given_str.size() - 1;

  while (left_idx <= right_idx) {
    if (given_str[left_idx] != given_str[right_idx]) {
      return false;
    }
    left_idx++;
    right_idx--;
  }
  return true;
}

bool CheckPalindromeRecursion(std::string str, int left_idx, int right_idx) {
  if (left_idx > right_idx) {
    return true;
  }
  return (str[left_idx] == str[right_idx]) && (CheckPalindromeRecursion(str, left_idx+1, right_idx-1));
}

int main (int argc, char** argv) {
  std::string given_str = "madam";

  // Check if the given_str is a Palindromic string
  bool is_palindrome = CheckPalindrome(given_str);
  if (is_palindrome) {
    std::cout << given_str << " is a palindrome (iterative solution)" << std::endl;
  }
  else {
    std::cout << given_str << " is not a palindrome (iterative solution)" << std::endl;
  }

  // Recursive Solution
  bool is_palindrome_recur = CheckPalindromeRecursion(given_str, 0, given_str.size()-1);
  if (is_palindrome_recur) {
    std::cout << given_str << " is a palindrome (recursion solution)" << std::endl;
  }
  else {
    std::cout << given_str << " is not a palindrome (recursion solution)" << std::endl;
  }

  // Given a string create a list of occurances of letters in the string
  std::string some_str = "abcdefghijklmnopqrstuvwxyzabcdefgh";
  int occurances[26] = {0};

  int idx = 0;
  while (idx != some_str.size()) {
    occurances[some_str[idx]- 'a'] += 1;
    idx++;
  }

  for (int i = 0; i != sizeof(occurances)/sizeof(occurances[0]); i++) {
    std::cout << occurances[i] << ",";
  }
  std::cout << std::endl;
  return 0;
}
