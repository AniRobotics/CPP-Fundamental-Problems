/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  int left = 0;
  int right = heights.size() - 1;
  
  int currentMax = 0;
  int maxSoFar = 0;

  while (left < right) {
    currentMax = (right - left)*min(heights[left], heights[right]);
    maxSoFar = max(currentMax, maxSoFar);
    
    if (heights[left] < heights[right]) {
      left++;
    }
    else {
      right--;
    }
  }

  std::cout << "Most water stored: " << maxSoFar << std::endl;

  return 0;
}
