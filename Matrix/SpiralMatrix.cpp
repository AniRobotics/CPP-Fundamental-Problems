/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  // Given matrix
  std::vector<std::vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

  // Read the matrix elements in spiral order
  int left = 0, right = matrix[0].size()-1;
  int top = 0, bottom = matrix.size()-1;
  int totalElements = matrix.size()*matrix[0].size();

  int count = 0;
  while (count < totalElements) {
    // Read top row from left to right
    for (int i = left; i <= right && count < totalElements; i++) {
      std::cout << matrix[top][i] << std::endl;
      count++;
    }
    top++; // shrink

    // Read right most column from top to bottom
    for (int i = top; i <= bottom && count < totalElements; i++) {
      std::cout << matrix[i][right] << std::endl;
      count++;
    }
    right--; // shrink

    // Read bottom row from right to left
    for (int i = right; i >= left && count < totalElements; i--) {
      std::cout << matrix[bottom][i] << std::endl;
      count++;
    }
    bottom--; // shrink

    // Read left column from bottom to top
    for (int i = bottom; i >= top && count < totalElements; i--) {
      std::cout << matrix[i][left] << std::endl;
      count++;
    }
    left++;  // shrink
  }

  return 0;
}
