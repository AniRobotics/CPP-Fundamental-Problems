/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest
node in T that has both p and q as descendants (where we allow a node to be a
descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Constraints:
All of the nodes' values will be unique.
p and q are different and both values will exist in the BST.
*/

#include "Utils.h"

using namespace std;

void LCA(std::shared_ptr<Node> node, int p, int q, int& lowVal) {
  if (node == nullptr) return;

  int value = node->value;
  if (value >= p && value < q) {
    lowVal = value;
    return;
  }

  LCA(node->left,p,q,lowVal);
  LCA(node->right,p,q,lowVal);
}

int main(int argc, char** argv) {
  std::vector<int> vec = {6,2,8,0,4,7,9,-1,-1,3,5}; // example 1
  std::shared_ptr<Node> root = BuildTree(vec);

  int p = 3, q = 5, lowVal;
  LCA(root,p,q,lowVal);
  std::cout << "Lowest common ancestor of " << p << " and "
            << q << " is: " << lowVal << std::endl;

  return 0;
}
