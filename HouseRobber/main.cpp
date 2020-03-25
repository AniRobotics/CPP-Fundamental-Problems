#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    
    // Amount of money placed is houses
    int numHouses = 4;
    int houseMoney[] = {1,2,3,1};
    
    // Idea: solve the problem in bottom up approach using dynamic programming.
    int dpArray[numHouses+1];
    
    dpArray[0] = 0;
    dpArray[1] = houseMoney[0];
    
    for (int i = 2; i <= numHouses; i++)
    {
        dpArray[i] = max(dpArray[i-1], houseMoney[i-1]+dpArray[i-2]);
    }
    
    std::cout << "Max money: " << dpArray[numHouses] << std::endl;
    
    return 0;
}

