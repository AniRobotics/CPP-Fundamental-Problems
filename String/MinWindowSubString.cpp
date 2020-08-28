/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include <iostream>

using namespace std;

int main(int argc, char** argv){
  std::string s = "ADOBECODEBANC";
  std::string t = "ABC";

  int charCount[26] = {0};
  for (char c : t) {
    charCount[c-'A'] += 1;
  }

  int winStart = 0;
  int minLength = s.size();

  int count = 0;
  for (int winEnd = 0; winEnd < (int)s.size(); winEnd++) {
    if (--charCount[s[winEnd]-'A'] >= 0) {
      count++;
      std::cout << "Found the letter: " << s[winEnd] << std::endl;
    }

    if (count == (int)t.size()) {
      std::cout << "Found: [" << winStart << "," << winEnd << "]" << std::endl;
    }

    while (count == (int)t.size()) {
      minLength = min(minLength,winEnd-winStart+1);
      if (++charCount[s[winStart]-'A'] > 0) {
        --count;
      }
      std::cout << "Shrinked Found: [" << winStart << "," << winEnd << "]" << std::endl;
      ++winStart;
    }
   // minLength = min(minLength,winEnd-winStart+1);
  }
  std::cout << "Length of minimum substring: " << minLength << std::endl;
  return 0;
}
