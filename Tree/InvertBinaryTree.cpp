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
*/

#include "Utils.h"

using namespace std;

std::shared_ptr<Node> invertTree(std::shared_ptr<Node> node) {
  if (node == nullptr) {
    return node;
  }

  std::shared_ptr<Node> left = invertTree(node->left);
  std::shared_ptr<Node> right = invertTree(node->right);

  node->left = right;
  node->right = left;

  return node;
}

int main (int argc, char** argv) {
  // Means no node to be added
  std::vector<int> firstVec = {1,2,3,4,-1,-1,5};

  // Call BuildTree method
  std::shared_ptr<Node> root = BuildTree(firstVec);
  TravLvlOrd(root);

  // Invert the tree
  std::cout << "\n\nInverting Binary Tree" << std::endl;
  invertTree(root);
  TravLvlOrd(root);

  return 0;
}
