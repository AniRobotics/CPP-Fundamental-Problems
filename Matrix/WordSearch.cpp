/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

#include <iostream>
#include <vector>

using namespace std;

bool searchWord(std::vector<std::vector<char>>& board, int row, int col, std::string word, int index) {
  if (index == word.size()) {
    return true;
  }

  if (row < 0 || row == board.size() || col < 0 || col == board[0].size()) {
    return false;
  }

  if (board[row][col] != word[index]) {
    return false;
  }
  
  std::cout << "found: " << board[row][col] << " at " << "[" << row << "," << col << "]" << std::endl;

  char temp = board[row][col];
  board[row][col] = '-';
  
  bool found = searchWord(board,row+1,col,word,index+1)||searchWord(board,row-1,col,word,index+1)||searchWord(board,row,col+1,word,index+1)||searchWord(board,row,col-1,word,index+1);

  board[row][col] = temp;

  return found;
}

int main(int argc, char** argv) {
  std::vector<std::vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  std::string word = "ABCCED";
  
  bool foundWord = false;
  for (size_t i = 0; i < board.size(); i++) {
    for (size_t j = 0; j < board[0].size(); j++) {
      if (board[i][j] == word[0]) {
        if (searchWord(board, i, j, word, 0)) {
          foundWord = true;
          std::cout << "word found" << std::endl;
          break;
        }
      }
    }
    if (foundWord) {
      break;
    }
  }

  return 0;
}
