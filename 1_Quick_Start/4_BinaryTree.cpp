#include <iostream>
#include <memory>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
  Node(int value) {
    this->value = value;
  }
  int value;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
};

std::shared_ptr<Node> BuildTreeLvlOrd(std::vector<int>& NodeVals) {
  std::cout << "\nInside function BuildTreeLvlOrd:\n" << std::endl;
  std::queue<std::shared_ptr<Node>> tempQ;
  std::shared_ptr<Node> root = std::make_shared<Node> (Node(NodeVals[0]));
  tempQ.push(root);

  int count = 1;
  while (!tempQ.empty()) {
    std::shared_ptr<Node> CurrentNodePtr = tempQ.front();
    tempQ.pop();

    if (count != NodeVals.size()) {
      CurrentNodePtr->left = std::make_shared<Node> (Node(NodeVals[count]));
      tempQ.push(CurrentNodePtr->left);
      count++;
    }

    if (count != NodeVals.size()) {
      CurrentNodePtr->right = std::make_shared<Node> (Node(NodeVals[count]));
      tempQ.push(CurrentNodePtr->right);
      count++;
    }
  }
  std::cout << "Tree building completed" << std::endl;
  std::cout << "--------------------\n" << std::endl;
  return root;
}

// BFS Tree Traversal : Level Order Traversal
void BinaryTreeTraverseLvlOrd(std::shared_ptr<Node> root) {
  std::cout << "Inside function BinaryTreeTraverseLvlOrd:\n" << std::endl;
  std::queue<std::shared_ptr<Node>> tempQ;

  if (root != nullptr) {
    tempQ.push(root);
  }

  while (!tempQ.empty()) {
    std::shared_ptr<Node> tempNode = tempQ.front();
    tempQ.pop();

    std::cout << "Parent: " << tempNode->value << std::endl;
    if (tempNode->left != nullptr) {
      tempQ.push(tempNode->left);
      std::cout << "Left Child: " << tempNode->left->value << std::endl;
    }
    else{
      std::cout << "Left Child: Null" << std::endl;
    }

    if (tempNode->right != nullptr) {
      tempQ.push(tempNode->right);
      std::cout << "Right Child: " << tempNode->right->value << std::endl;
    }
    else{
      std::cout << "Right Child: Null" << std::endl;
    }
    std::cout << "------" << std::endl;
  }
}

void PreOrdRecursive(std::shared_ptr<Node> node) {
  if (node != nullptr) {
    std::cout << node->value << std::endl;
    PreOrdRecursive(node->left);
    PreOrdRecursive(node->right);
  }
}

void BinaryTreeTraversePreOrd(std::shared_ptr<Node> root) {
  std::cout << "\nInside function BinaryTreeTraversePreOrd:\n" << std::endl;
  PreOrdRecursive(root);
  std::cout << "------" << std::endl;
}

int main(int argc, char** argv) {
  std::vector<int> NodeVals = {12,65,98,78,16,35,46,51,100};

  // Build tree in Level Order Filling
  std::shared_ptr<Node> root = BuildTreeLvlOrd(NodeVals);

  // Traverse the tree in Level Order
  BinaryTreeTraverseLvlOrd(root);

  // Traverse Tree using DFS in Post Order Manner
  BinaryTreeTraversePreOrd(root);

  return 0;
}
