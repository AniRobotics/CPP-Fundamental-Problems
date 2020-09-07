/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting
node to any node in the tree along the parent-child connections. The path must
contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/

#include "Utils.h"

using namespace std;

int maxSum = 0;

int maxPathSum(std::shared_ptr<Node> node) {
  if (node == nullptr) {
    return 0;
  }

  int leftSum = max(0,maxPathSum(node->left));  // consider only +ve contribution
  int rightSum = max(0,maxPathSum(node->right));// consider only +ve contribution

  maxSum = max(maxSum,leftSum+rightSum+node->value); // max so far continuous branches
  std::cout << "Max path sum upto node " << node->value << " is " << max(leftSum,rightSum)+node->value << std::endl;
  return max(leftSum,rightSum)+node->value;
}

int main (int argc, char** argv) {
  // -1 means no node to be added
  std::vector<int> firstVec = {-10,9,20,-1,-1,15,7};

  // Call BuildTree method
  std::shared_ptr<Node> root = BuildTree(firstVec);
  TravLvlOrd(root);

  // Call Maximum Path Sum method
  maxPathSum(root);
  std::cout << "Max sum: " << maxSum << std::endl;

  return 0;
}
