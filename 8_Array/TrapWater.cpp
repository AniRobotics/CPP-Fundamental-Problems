/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char** argv) {
  std::vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  
  int left_max[heights.size()], right_max[heights.size()];
  left_max[0] = heights[0];
  right_max[heights.size()-1] = heights[heights.size()-1];
  
  for (unsigned int i = 1; i < heights.size(); i++) {
    left_max[i] = max(left_max[i-1],heights[i]);
    right_max[heights.size()-1-i] = max(right_max[heights.size()-i],heights[heights.size()-1-i]);
  }

  int water_count = 0;
  for (unsigned int i = 0; i < heights.size(); i++) {
    water_count += min(left_max[i], right_max[i]) - heights[i];
  }

  std::cout << "Total water: " << water_count << std::endl;

  return 0;
}

