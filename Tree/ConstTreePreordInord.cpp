/*
Fact-1:
Both in preorder and inorder traversals, we first complete traversing the left
subtree and then complete traversing the right subtree, although the indices of
the parent nodes could be different.
Therefore, given the preorder and inorder node lists, there will be a common
index in both the list, left of which will be the nodes of the left subtree and
right of which will be the nodes of the right subtree.

Fact-2:
Given a preorder traversal node list,
(a) the first node is the root of the tree.
(b) the second node is the left child of the root.
(c) the index of the right child in the preorder list will be equal to index of
the root node in the inorder list plus 1.
*/

#include "Utils.h"
#include <vector>

using namespace std;

std::shared_ptr<Node> constructTree(int preordRootIdx, int inordStrIdx, int inordEndIdx, std::vector<int> preorder, std::vector<int> inorder) {
  if (preordRootIdx >= preorder.size() || inordStrIdx > inordEndIdx) {
    // std::cout << "returning nullptr" << std::endl;
    return nullptr;
  }

  // std::cout << preordRootIdx << "," << preorder[preordRootIdx] << std::endl;
  std::shared_ptr<Node> root = std::make_shared<Node> (Node(preorder[preordRootIdx]));

  int inordRootIdx;
  for (int i = inordStrIdx; i <= inordEndIdx; i++) {
    if (inorder[i] == root->value) {
      inordRootIdx = i;
    }
  }

  root->left = constructTree(preordRootIdx+1, inordStrIdx, inordRootIdx-1, preorder, inorder);
  // std::cout << "inordEndIdx: " << inordEndIdx << "," << "inorder.size()-1: " << inorder.size()-1 << std::endl;
  root->right = constructTree(preordRootIdx + inordRootIdx - inordStrIdx + 1, inordRootIdx + 1, inordEndIdx, preorder, inorder);

  return root;
}

int main(int argc, char** argv) {
  // Example 1
  // std::vector<int> preorder = {3,9,20,15,7};
  // std::vector<int> inorder = {9,3,15,20,7};

  // Example 2
  std::vector<int> preorder = {3,9,10,18,20,15,7};
  std::vector<int> inorder = {10,9,18,3,15,20,7};

  std::shared_ptr<Node> root = constructTree(0, 0, inorder.size()-1, preorder, inorder);
  TravLvlOrd(root);

  return 0;
}
