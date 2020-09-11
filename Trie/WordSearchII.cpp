/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



Example:

Input:
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
*/

#include "Utils.h"
#include <vector>

void dfs(int i, int j, TrieNode* node, std::string s, std::vector<std::vector<char>>& board, std::vector<std::string>& res) {
  if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == ' ') {
    return;
  }

  char temp = board[i][j];
  if (node->links[temp - 'a'] == nullptr) {
    return;
  }

  board[i][j] = ' ';
  std::cout << temp << std::endl;
  std::string ns = s+temp;
  if (node->links[temp - 'a']->isEnd) {
    res.push_back(ns);
    std::cout << "Found word: " << ns << std::endl;
  }

  dfs(i+1, j, node->links[temp - 'a'], ns, board, res);
  dfs(i-1, j, node->links[temp - 'a'], ns, board, res);
  dfs(i, j+1, node->links[temp - 'a'], ns, board, res);
  dfs(i, j-1, node->links[temp - 'a'], ns, board, res);

  board[i][j] = temp;
}

int main(int argc, char** argv) {
  Trie* obj = new Trie();

  std::vector<std::vector<char>> board = {{'o','a','a','n'},
                                          {'e','t','a','e'},
                                          {'i','h','k','r'},
                                          {'i','f','l','v'}};

  std::vector<std::string> words = {"oath","pea","eat","rain"};

  // Insert all the words in the Trie
  for (auto word : words) {
    obj->insert(word);
  }

  // Check each element in the grid that matches with the first node char
  // and call DFS from there.
  std::vector<std::string> res;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      // std::cout << "Current character: " << board[i][j] << std::endl;
      if (obj->root->links[board[i][j]-'a'] != nullptr) {
        // std::cout << "Got match: " << board[i][j] << " main function" << std::endl;
        dfs(i,j,obj->root,"",board,res);
      }
    }
  }

  // Print the searched words
  std::cout << "Searched words" << std::endl;
  for (auto word : res) {
    std::cout << word << std::endl;
  }

  delete obj;
  return 0;
}
