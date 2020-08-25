/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
*/

#include "tree_utils.h"

using namespace std;

std::shared_ptr<Node> InvertBinaryTree(std::shared_ptr<Node> node) {
  if (node == nullptr) {
    return node;
  }

  std::shared_ptr<Node> left = InvertBinaryTree(node->left);
  std::shared_ptr<Node> right = InvertBinaryTree(node->right);

  node->left = right;
  node->right = left;

  return node;
}

int main(int argc, char** argv) {
  std::vector<int> node_vals = {1, 2, 3, 4, 5};

  // Build tree using BFS traversal
  std::shared_ptr<Node> root = BuildTree(node_vals);

  // Print the tree node values
  PrintTree(root);

  // Invert the binary tree
  InvertBinaryTree(root);

  // Print the tree node values
  PrintTree(root);

  return 0;
}

