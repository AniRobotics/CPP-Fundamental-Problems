/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

#include <iostream>

using namespace std;

int main (int argc, char** argv) {
  int numStair = 4;
  int dpArray[numStair+1];

  // initialize dpArray
  dpArray[0] = 1;
  dpArray[1] = 1;
  dpArray[2] = 2;

  // Since any step can be reached, either from the previous or two previous steps
  // we only need to consider the previous and previous to previous steps.
  for (size_t i = 3; i < sizeof(dpArray)/sizeof(dpArray[0]); i++) {
    dpArray[i] = dpArray[i-1] + dpArray[i-2];
  }

  std::cout << numStair << " stairs can be climed in "
  << dpArray[sizeof(dpArray)/sizeof(dpArray[0]) - 1] << " ways." << std::endl;

  return 0;
}
