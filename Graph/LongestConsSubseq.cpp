/*
Given an unsorted array of integers, find the length of the longest consecutive
elements sequence.

Your algorithm should run in O(n) complexity.

Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char** argv) {
  // std::vector<int> nums = {100,4,200,1,3,2}; // Example 1
  std::vector<int> nums = {100,4,200,1,3,5}; // Example 2

  std::set<int> given;
  for (auto i : nums) {
    given.insert(i);
  }

  int res = 0;
  std::vector<int> subseq;
  for (int i : nums) {
    if (given.find(i-1) != given.end()) {
      int j = i-1;
      std::vector<int> currentSubseq;
      while (given.find(j) != given.end()) {
        currentSubseq.push_back(j);
        j++;
      }
      res = max(res, j-i+1);
      if (res == j - i + 1) {
        subseq = currentSubseq;
      }
    }
  }

  std::cout << "Length of longest consecutive subsequence: " << res << std::endl;
  std::cout << "Elements of the consecutive subsequence are: ";
  for (auto i : subseq) std::cout << i << ",";
  std::cout << std::endl;

  return 0;
}
