/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  std::vector<int> arr = {10,9,2,5,3,7,101,18,105};
  int dpArray[arr.size()] = {0};
  dpArray[0] = 1;

  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > arr[i-1]) {
      dpArray[i] = dpArray[i-1] + 1;
    }
    else {
      dpArray[i] = dpArray[i-1];
    }
  }

  std::cout << "Length of the longest increasing subsequnce: "
   << dpArray[arr.size()-1] << std::endl;

  return 0;
}
