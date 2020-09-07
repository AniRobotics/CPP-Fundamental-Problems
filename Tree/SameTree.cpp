#include "Utils.h"

using namespace std;

int SameTree(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2) {
  if (node1 == nullptr && node2 == nullptr) {
    return true;
  }
  else if (node1 != nullptr && node2 == nullptr) {
    return false;
  }
  else if (node1 == nullptr && node2 != nullptr) {
    return false;
  }
  else if (node1->value != node2->value) {
    return false;
  }

  return (node1->value == node2->value)
         && SameTree(node1->left,node2->left)
         && SameTree(node1->right,node2->right);
}

int main (int argc, char** argv) {
  // -1 means no node to be added
  std::vector<int> firstVec = {1,2,3};
  std::vector<int> secondVec = {1,2,3};

  // Call BuildTree method
  std::shared_ptr<Node> firstRoot = BuildTree(firstVec);
  std::shared_ptr<Node> secondRoot = BuildTree(secondVec);

  // Level order traversal of Tree
  bool same = SameTree(firstRoot, secondRoot);

  // Height of binary tree
  if (same) {
    std::cout << "TRUE: First and second trees are same" << std::endl;
  }
  else {
    std::cout << "FALSE: First and second trees are diferent" << std::endl;
  }

  return 0;
}
