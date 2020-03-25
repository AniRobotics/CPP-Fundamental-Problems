#include <iostream>
#include <algorithm>

using namespace std;

// Idea: Use dynamic programming bottom up approach.
// Create a dpArray of size amount+1, where i-th cell would contain
// the minimum number of coins required to make amount i. 

int fewestCoins(int coins[], int & num_coins, const int &amount)
{
    int min_num_coins;
    
    // Create an array to hold the minimum number of coins required
    int dpArray[amount+1];
    
    // Assign an impossible value to each cell
    for (int i = 0; i < amount+1; i++)
    {
        dpArray[i] = amount+1;
    }
    
    // Reassign the first cell of the dpArray to 1
    dpArray[0] = 0;
    
    // Now fill-in the other cells with right values
    for (int i = 1;  i < amount+1; i++)
    {
        // Check all denominations available <= i
        for (int j = 0; j < num_coins; j++)
        {
            if (coins[j] <= i)
            {
                dpArray[i] = min(dpArray[i], 1+dpArray[i - coins[j]]);
            }
        }
        std::cout << "dpArray[" << i << "]=" << dpArray[i] << std::endl;
    }
    
    // Now the value in the last cell of the dpArray should have the minimum number of coins
    if (dpArray[amount+1] > amount)
    {
        return -1; // impossible case
    }
    else
    {
        min_num_coins = dpArray[amount];
    }
    
    return min_num_coins;
}

int main(int argc, char** argv) 
{
    int num_coins = 3; 
    int coins[] = {1,2,5};
    int target_amount = 11;
    
    int min_denomination = fewestCoins(coins, num_coins, target_amount);
    std::cout << "Minimum number of coins: " << min_denomination << std::endl;
    return 0;
}

