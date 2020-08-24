/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char** argv) {
  std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int maxSumArr[nums.size()];
  maxSumArr[0] = nums[0];
  
  int maxSum = nums[0];
  for (unsigned int i = 1; i < nums.size(); i++) {
    maxSumArr[i] = max(maxSumArr[i-1] + nums[i], nums[i]);
    if (maxSum < maxSumArr[i]) {
        maxSum = maxSumArr[i];
    }
  }
  
  std::cout << "Max subarray sum: " << maxSum << std::endl;
  
  //for (unsigned int i = 0; i < nums.size(); i++) {
  //  std::cout << maxSumArr[i] << std::endl;
  //}
  
  return 0;
}
