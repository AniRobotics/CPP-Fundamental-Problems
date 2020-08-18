#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

vector<int> TwoSum(vector<int>& nums, int target) {
    std::unordered_map<int,int> umap;
    std::vector<int> indices;
    int index = 0;
    for (auto a : nums) {
      auto it = umap.find(target-a);
      if (it != umap.end()) {
        indices.push_back(it->second);
        indices.push_back(index);
        break;
      }
      umap[a] = index++;
    }
    return indices;
}

int main(int argc, char** argv) {
  std::vector<int> nums = {2,7,11,15};
  int target = 22;
  
  std::vector<int> indices = TwoSum(nums,target);
  // Print the indices
  for (auto i : indices) {
    std::cout << i << ",";
  }
  std::cout << std::endl;
  return 0;
}

