/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

/*
Idea: use two built in functions,
a. isalnum(char) -> to know if a character is alphanumeric or not
b. tolower(char) -> to convert any character to a lower case
*/

#include <iostream>

using namespace std;

int main (int argc, char** argv) {
  // std::string s = "A man, a plan, a canal: Panama";
  std::string s = "race a car";

  int left = 0, right = s.length() - 1;
  while (left < right) {
    while (!isalnum(s[left])) {
      left++;
    }

    while (!isalnum(s[right])) {
      right--;
    }

    if (left < right) {
      if (tolower(s[left]) == tolower(s[right])) {
        left++;
        right--;
      }
      else {
        std::cout << "Not a palindrome: ";
        // std::cout << "left: " << left << "," << "right: " << right << std::endl;
        std::cout << s[left] << "!=" << s[right] << std::endl;
        return 0;
      }
    }
  }

  std::cout << "A valid palindrome" << std::endl;

  return 0;
}
