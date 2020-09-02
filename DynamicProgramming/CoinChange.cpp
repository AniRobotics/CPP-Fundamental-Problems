/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/

#include <iostream>

using namespace std;

int main (int argc, char** agrv) {
  int coins[] = {1,2,5};
  int amount = 11;

  // Create a dpArray and initialize its first element with 0. This means, we need
  // 0 coin to make up the amount 0.
  int dpArray[amount+1] = {0};

  for (int i = 1; i <= amount; i++) {
    for (size_t j = 0; j < sizeof(coins)/sizeof(coins[0]); j++) {
      if (coins[j] <= i) {
        dpArray[i] = dpArray[i-coins[j]]+1;
      }
      else {
        break;
      }
    }
  }

  std::cout << amount << " can be made up with minimum of "
  << dpArray[amount] << " coins" << std::endl;
  return 0;
}
