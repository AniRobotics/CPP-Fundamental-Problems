/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:

The order of returned grid coordinates does not matter.
Both m and n are less than 150.


Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void dfs(std::vector<std::vector<int>>& matrix, int row, int col, int value, std::vector<std::vector<int>>& ocean) {
  if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size()) {
    return;
  }
  else if (matrix[row][col] < value) {
    return;
  }
  else if (ocean[row][col] == 1) {
    return;
  }
  else {
    ocean[row][col] = 1;

    // Cal dfs in all the other directions
    dfs(matrix, row+1, col, matrix[row][col], ocean);
    dfs(matrix, row-1, col, matrix[row][col], ocean);
    dfs(matrix, row, col+1, matrix[row][col], ocean);
    dfs(matrix, row, col-1, matrix[row][col], ocean);
  }
}

int main(int argc, char** argv) {
  std::vector<std::vector<int>> matrix = {{1,2,2,3,5},
                                          {3,2,3,4,4},
                                          {2,4,5,3,1},
                                          {6,7,1,4,5},
                                          {5,1,1,2,4}};

  // Create oceans (pacific and atlantic) with zero initialized
  std::vector<std::vector<int>> pacific(matrix.size(), std::vector<int> (matrix[0].size(), 0));
  std::vector<std::vector<int>> atlantic(matrix.size(), std::vector<int> (matrix[0].size(), 0));

  // Move inside from TOP and BOTTOM (column changes)
  for (size_t col = 0; col < matrix[0].size(); col++) {
    dfs(matrix, 0, col, matrix[0][col], pacific);
    dfs(matrix, matrix.size()-1, col, matrix[matrix.size()-1][col], atlantic);
  }

  // Move inside from LEFT and RIGHT (row changes)
  for (size_t row = 0; row < matrix.size(); row++) {
    dfs(matrix, row, 0, matrix[row][0], pacific);
    dfs(matrix, row, matrix[0].size()-1, matrix[row][matrix[0].size()-1], atlantic);
  }

  // Check for the common cells with water flow
  std::vector<std::vector<int>> res;
  for (size_t i = 0; i < matrix.size(); i++) {
    for (size_t j = 0; j < matrix[0].size(); j++) {
      if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
        std::vector<int> cell = {i,j};
        res.push_back(cell);
      }
    }
  }

  // Print the res
  for (size_t i = 0; i < res.size(); i++) {
    std::cout << "[" << res[i][0] << "," << res[i][1] << "], ";
  }

  std::cout << std::endl;

  return 0;
}
