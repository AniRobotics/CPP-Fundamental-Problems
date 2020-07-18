#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    // Given grid
    int num_rows = 3, num_cols = 3;
    int grid[3][3] = {{1,3,1},{1,5,1},{4,2,1}};
    
    // Since only allowed movements are right and down, any cell in the first 
    // row can be reached from left and any cell in the first column can be 
    // reached from upper cell.
    
    // So we will create a separate grid and fill in the cells with minimum values
    int minSumGrid[3][3];
    minSumGrid[0][0] = grid[0][0];
    
    // Fill-in the first row
    for (int i = 1; i < num_cols; i++)
    {
        minSumGrid[0][i] = grid[0][i] + minSumGrid[0][i-1];
    }
    
    // Fill-in the first column
    for (int i = 1; i < num_rows; i++)
    {
        minSumGrid[i][0] = grid[i][0] + minSumGrid[i-1][0];
    }
    
    // Fill-in the rest of the cells
    for (int i = 1; i < num_rows; i++)
    {
        for (int j = 1; j < num_cols; j++)
        {
            minSumGrid[i][j] = grid[i][j] + min(minSumGrid[i-1][j], minSumGrid[i][j-1]);
        }
    }
    
//    // Print the minSumGrid
//    for (int i = 0; i < num_rows; i++)
//    {
//        for (int j = 0; j < num_cols; j++)
//        {
//            std::cout << minSumGrid[i][j] << ",";
//        }
//        std::cout << std::endl;
//    }
    
    std::cout << "Min path sum: " << minSumGrid[num_rows-1][num_cols-1] << std::endl;
    return 0;
}

