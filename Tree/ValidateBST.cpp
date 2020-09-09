/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

/*
This problem is harder than it appears. Please note the two properties of a BST
(a) at any node, all the nodes in its right subtree (not only immediate right
child) should have value less than the node value.
(b) at any node, all the nodes in its left subtree (not only immediate left
child) must have their values less than that of the current node value.
*/

#include "Utils.h"

using namespace std;

bool validateBST(std::shared_ptr<Node> node, int lower, int upper) {
  if (node == nullptr) return true;

  int value = node->value;
  if (lower != -1 && value >= lower) return false;
  if (upper != -1 && value <= upper) return false;

  if (!validateBST(node->left,lower,value)) return false;
  if (!validateBST(node->right,value,upper)) return false;

  return true;
}

int main (int argc, char** argv) {
  // std::vector<int> vec = {5,1,4,-1,-1,3,6}; // example 1
  std::vector<int> vec = {2,1,3}; // example 2
  std::shared_ptr<Node> root = BuildTree(vec);

  // Call validate BST
  bool answer = validateBST(root, -1, -1);

  if (answer) {
    std::cout << "Given tree is a BST" << std::endl;
  }
  else {
    std::cout << "Given tree is not a BST" << std::endl;
  }
  return 0;
}
