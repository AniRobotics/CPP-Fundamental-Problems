#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

std::vector<std::vector<int>> ThreeSum(vector<int>& nums) {
    std::vector<std::vector<int>> valid_triplets;
    
    sort(nums.begin(), nums.end());
    int left_idx, right_idx;
    for (size_t i = 0; i < nums.size(); i++) {
        left_idx = i+1;
        right_idx = nums.size()-1;
        if (i>0 && nums[i] == nums[i-1]) {
          continue;
        }
        while (left_idx < right_idx) {
          int threeSum = nums[i] + nums[left_idx] + nums[right_idx];
          if (threeSum > 0) {
            right_idx--;
          }
          else if (threeSum < 0) {
            left_idx++;
          }
          else {
            std::vector<int> new_triplet = {nums[i],nums[left_idx],nums[right_idx]};
            valid_triplets.push_back(new_triplet);
            left_idx++;
            while (nums[left_idx] == nums[left_idx-1] && left_idx < right_idx) {
              left_idx++;
            }
          }
        }
    }
    return valid_triplets;
}

int main(int argc, char** argv) {
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> valid_triplets = ThreeSum(nums);
  
  // Print the valid triplet
  for (int i = 0; i < valid_triplets.size(); i++) {
    std::cout << "(";
    for (int j = 0; j < valid_triplets[0].size(); j++) {
      std::cout << valid_triplets[i][j] << ",";
    }
    std::cout << ")" << std::endl;
  }
  
  return 0;
}


