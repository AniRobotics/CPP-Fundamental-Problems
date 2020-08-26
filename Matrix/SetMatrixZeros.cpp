/*
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Example: 1
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example: 2
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
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

int main (int argc, char** argv) {
  std::vector<std::vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
  std::cout << "Given matrix: " << std::endl;
  PrintMatrix(matrix);

  bool firstRowZeroFlag = false, firstColZeroFlag = false;
  
  // Set the firtRowZeroFlag
  for (size_t i = 0; i < matrix[0].size(); i++) {
    if (matrix[0][i] == 0) {
      firstRowZeroFlag = true;
    }
  }

  // Set the firtColZeroFlag
  for (size_t i = 0; i < matrix.size(); i++) {
    if (matrix[i][0] == 0) {
      firstColZeroFlag = true;
    }
  }

  // Set the corresponding first row and first column elements to zero
  // if the related (i,j) cell elements are zeros.
  for (size_t i = 1; i < matrix.size(); i++) {
    for (size_t j = 1; j < matrix[0].size(); j++) {
      if (matrix[i][j] == 0) {
        matrix[0][j] = 0;
        matrix[i][0] = 0;
      }
    }
  }

  // Given the updated matrix, if the elements in the first row or 
  // column are zeros, then  
  for (size_t i = 1; i < matrix.size(); i++) {
    for (size_t j = 1; j < matrix[0].size(); j++) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  // Now make all the remaining elements of the first row to zero if 
  // firstRowZeroFlag is set as zero.
  if (firstRowZeroFlag) {
    for (size_t i = 0; i < matrix[0].size(); i++) {
      matrix[0][i] = 0;
    }
  }

  // Now make all the remaining elements of the first column to zero if 
  // firtColZeroFlag is set as zero.
  if (firstColZeroFlag) {
    for (size_t i = 0; i < matrix.size(); i++) {
      matrix[i][0] = 0;
    }
  }

  std::cout << "After the manipulation is completed: " << std::endl;
  PrintMatrix(matrix);

  return 0;
}

