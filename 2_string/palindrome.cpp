#include <iostream>
using namespace std;

bool palindrome_iterative(std::string word) {
  // Check palindrome iterative solution
  int i = 0, j = word.size()-1;
  while(i <= j) {
    if (word[i] != word[j]) {
      // std::cout << i << "," << j << std::endl;
      std::cout << "The word is not a palindrome" << std::endl;
      return false;
    }
    i++;
    j--;
  }
  std::cout << "The word is a palindrome" << std::endl;
  return true;
}

bool palindrome_recursive(int left, int right, std::string word) {
  if (left <= right) {
    if (word[left] != word[right]) {
      return false;
    }
    return palindrome_recursive(left+1, right-1, word);
  }
  else {
    return true;
  }
}

int main (int argc, char** argv) {
  std::string word = "madam";

  // Iterative solution
  palindrome_iterative(word);

  // Recurvice solution
  bool result = palindrome_recursive(0, word.size()-1, word);
  std::cout << word << " is a palindrome: " << ((result) ? "true" : "false") << std::endl;

  return 0;
}
