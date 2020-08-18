#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/

vector<int> TwoSum(vector<int>& numbers, int target) {
  std::vector<int> indices;
  int left_idx = 0, right_idx = numbers.size()-1;
  int tempSum = 0;
  
  while(left_idx < right_idx) {
    tempSum = numbers[left_idx] + numbers[right_idx];
    if (tempSum > target) {
      right_idx--;
    }
    else if (tempSum < target) {
      left_idx++;
    }
    else {
      indices.push_back(left_idx);
      indices.push_back(right_idx);
      break;
    }
  }
  
  return indices;
}

int main(int argc, char** argv) {
  std::vector<int> nums = {2,7,11,15};
  int target = 26;
  
  std::vector<int> indices = TwoSum(nums,target);
  // Print the indices
  for (auto i : indices) {
    std::cout << i << ",";
  }
  std::cout << std::endl;
  return 0;
}
