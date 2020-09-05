/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  std::vector<int> nums = {2,3,1,1,4};

  // Since we are already given the max step size at a given index, we can adopt
  // top down approach which will given the solution in O(n).
  // We will assume, we already have reached the last index and need to figure
  // out, can we go back to index 0.

  // This problem is very similar to frog jump problem, unlike this problem, in frog
  // jump problem jump size varies so we need to apply back tracking.

  int goodIndex = nums.size() - 1;
  for (int i = nums.size() - 2; i >= 0; i--) {
    if (i+nums[i] >= goodIndex) {
      goodIndex = i;
      std::cout << goodIndex << std::endl;
    }
  }

  if (goodIndex == 0) {
    std::cout << "Goal can be reached" << std::endl;
  }
  else {
    std::cout << "Goal can not be reached" << std::endl;
  }

  return 0;
}
