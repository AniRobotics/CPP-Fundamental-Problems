#include "Utils.h"

using namespace std;

int FindTreeHeight(std::shared_ptr<Node> node) {
  if (node == nullptr) {
    return 0;
  }

  return max(FindTreeHeight(node->left),FindTreeHeight(node->right))+1;
}

int main (int argc, char** argv) {
  // -1 means no node to be added
  std::vector<int> vec = {3,9,20,-1,-1,15,7,-1,2};

  // Call BuildTree method
  std::shared_ptr<Node> treeRoot = BuildTree(vec);

  // Level order traversal of Tree
  TravLvlOrd(treeRoot);

  // Height of binary tree
  int treeHeight = FindTreeHeight(treeRoot);
  std::cout << "Height of the tree is: " << treeHeight << std::endl;

  return 0;
}
