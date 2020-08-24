/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  std::vector<int> nums = {1,2,3,4};
  
  // Create two arrays to hold left and right products
  int left_prod[nums.size()], right_prod[nums.size()], output[nums.size()];
  
  // Fill in the left_prod array
  left_prod[0] = 1;
  for (unsigned int i = 0; i < nums.size()-1; i++) {
    left_prod[i+1] = nums[i]*left_prod[i];
  }
  
  // Fill in the right_prod array
  right_prod[nums.size()-1] = 1;
  for (int i = nums.size()-2; i >= 0; i--) {
    right_prod[i] = nums[i+1]*right_prod[i+1];
  }
  
  
  // Fill in the output array
  for (unsigned int i = 0; i < nums.size(); i++) {
    output[i] = left_prod[i] * right_prod[i];
  }
  
  // Print the output array
  for (unsigned int i = 0; i < nums.size(); i++) {
    std::cout << output[i] << ",";
  }
  std::cout << std::endl;
  
  
  return 0;
}

