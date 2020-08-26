/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

#include <iostream>
#include <vector>

using namespace std;

void PrintMatrix(std::vector<std::vector<int>>& vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    for (size_t j = 0; j < vec[0].size(); j++) {
      std::cout << vec[i][j] << ",";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char** argv) {
  std::vector<std::vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
  std::cout << "Given matrix: " << std::endl;
  PrintMatrix(matrix);

  // Get the transpose of the matrix
  for (size_t i = 0; i < matrix.size(); i++) {
    for (size_t j = i; j < matrix[0].size(); j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
  std::cout << "After Transpose operation: " << std::endl;
  PrintMatrix(matrix);

  // Reverse each row
  for (size_t i = 0; i < matrix.size(); i++) {
    int j = 0, k = matrix[0].size()-1;
    while (j < k) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[i][k];
      matrix[i][k] = temp;
      j++, k--;
    }
  }

  std::cout << "After Transpose and Reverse operation: Rotation" << std::endl;
  PrintMatrix(matrix);

  return 0;
}
