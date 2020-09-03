/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

/*
This is the same as climb stair problem. The question we need to ask is: how many ways
we can split a string by taking two and/or one characters at a time.
*/

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  std:string s = "226"; // example 1
  // std:string s = "266"; // example 2

  // Create a dpArray
  int dpArray[s.length()+1] = {0};
  dpArray[0] = 1;
  dpArray[1] = 1;

  for (size_t i = 2; i <= s.length(); i++){
    int unitDigit = (int)s[i-1] - 48;
    int doubleDigit = 10*((int)s[i-2] - 48)+ unitDigit;
    std::cout << doubleDigit << std::endl;
    if (doubleDigit <= 26) {
      dpArray[i] = dpArray[i-1] + dpArray[i-2];
    }
    else{
      dpArray[i] = dpArray[i-1];
    }
  }

  std::cout << "Decode ways: " << dpArray[s.length()] << std::endl;

  return 0;
}
