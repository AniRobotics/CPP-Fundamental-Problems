/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char** argv) {
  std::vector<int> nums = {2, 3, -2, 4};
  int maxProdArr[nums.size()];
  int minProdArr[nums.size()];
  
  maxProdArr[0] =  nums[0];
  minProdArr[0] =  nums[0];
  
  int maxProd = nums[0];
  int minProd = nums[0];
  
  for (unsigned int i = 1; i < nums.size(); i++) {
    maxProdArr[i] = max(max(maxProdArr[i-1]*nums[i], minProdArr[i-1]*nums[i]), nums[i]);
    minProdArr[i] = min(min(maxProdArr[i-1]*nums[i], minProdArr[i-1]*nums[i]), nums[i]);
    
    if (maxProd < maxProdArr[i]) {
      maxProd = maxProdArr[i];
    }
    
    if (minProd > minProdArr[i]) {
      minProd = minProdArr[i];
    }
  }
  
  std::cout << "Max product: " << maxProd << std::endl;
  
  return 0;
}
