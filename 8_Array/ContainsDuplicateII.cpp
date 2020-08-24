/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char** argv) {
  int nums[] = {1,2,3,1};
  int k = 3;
  
  std::unordered_map<int,int> und_map;
  int curr_idx = 0;
  bool duplicate_flag = false;
  
  for (int i : nums) {
    auto found_itr = und_map.find(i);
    if (found_itr != und_map.end() && found_itr->second - curr_idx <= k) {
      duplicate_flag = true;
    }
    else {
      und_map[i] = curr_idx++;
    }
  }
  
  if (duplicate_flag) {
    std::cout << "Duplicate exists " << std::endl;
  }
  else {
   std::cout << "No duplicate exists" << std::endl; 
  }
  return 0;
}
