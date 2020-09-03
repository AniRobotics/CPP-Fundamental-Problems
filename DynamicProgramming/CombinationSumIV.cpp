/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.


Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/

/*
Idea: This problem is very similar to coin change problem, except it asks for
all the combinations, instead of minimum number of coins.
*/

#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char** argv) {
  std::vector<int> nums = {1,2,3};
  int target = 4;

  // Create a dpArray
  int dpArray[target+1] = {0};
  dpArray[0] = 1;  // initialize the dpArray's first cell with 1.

  // Fill in the dpArray
  for (int i = 1; i <= target; i++) {
    for (size_t j = 0; j < nums.size(); j++) {
      if (i-nums[j] >= 0) {
        dpArray[i] += dpArray[i-nums[j]];
      }
      else{
        break;
      }
    }
  }

  std::cout << "Number of combinations: " << dpArray[target] << std::endl;

  return 0;
}
