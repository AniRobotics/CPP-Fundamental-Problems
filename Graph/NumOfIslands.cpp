/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically. You may assume all four edges of the grid are all
surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

#include <iostream>
#include <vector>

using namespace std;

void dfs(std::vector<std::vector<char>>& grid, int row, int col) {
  if (row < 0 || row >= (int)grid.size() || col < 0 || col >= (int)grid[0].size()) {
    return;
  }
  else if (grid[row][col] == '0') {
    return;
  }
  else {
    grid[row][col] = '0';

    dfs(grid, row+1, col);
    dfs(grid, row-1, col);
    dfs(grid, row, col+1);
    dfs(grid, row, col-1);
  }
}

int main(int argc, char** argv) {
  std::vector<std::vector<char>> grid = {{'1','1','0','0','0'},
                                         {'1','1','0','0','0'},
                                         {'0','0','1','0','0'},
                                         {'0','0','0','1','1'}};

  int numIsland = 0;
  for (size_t i = 0; i < grid.size(); i++) {
    for (size_t j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == '1') {
        dfs(grid,i,j);
        numIsland++;
      }
    }
  }

  std::cout << "No. of island: " << numIsland << std::endl;

  return 0;
}
