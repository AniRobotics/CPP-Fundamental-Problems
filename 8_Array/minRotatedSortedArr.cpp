/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  
  int left = 0;
  int right = nums.size() - 1;
  
  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid] > nums[left]) {
      left = mid+1;
    }
    else {
      right = mid;
    }
    if (nums[mid] < nums[mid-1]) {
      std::cout << "Minimum element: " << nums[mid] << std::endl;
      std::cout << "Minimum element index: " << mid << std::endl;
    }
  }
  
  return 0;
}
