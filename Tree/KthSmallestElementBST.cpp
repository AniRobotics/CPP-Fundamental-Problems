/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.



Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

/*
Idea: Inorder traversal of a BST gives node values in sorted order.
*/

#include "Utils.h"

using namespace std;

void inorderTrav(std::shared_ptr<Node> node, std::vector<int>& vec, int k) {
  if (node == nullptr) return;

  inorderTrav(node->left, vec, k);  // traverse left
  vec.push_back(node->value);       // update the sorted list

  if ((int)vec.size() == k) return; // if list size is equal to k, return
  inorderTrav(node->right, vec, k); // traverse right

  return;
}

int main (int argc, char** argv) {
  // Build the BST
  std::vector<int> vec = {5,3,6,2,4,-1,-1,1};
  std::shared_ptr<Node> root = BuildTree(vec);

  // Start of finding k-th smallest element in BST
  int k = 3;
  std::vector<int> sortedEle;

  inorderTrav(root, sortedEle, k);

  std::cout << k << "-th smallest element is: " << sortedEle[k-1] << std::endl;

  return 0;
}
