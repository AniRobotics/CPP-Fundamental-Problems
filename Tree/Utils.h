#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <memory>
#include <queue>

// Tree node
class Node{
public:
  int value;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
  Node(int val) : value(val) {}
};

// Function to build the tree
std::shared_ptr<Node> BuildTree(std::vector<int>& vec) {
  // Start building the tree
  std::shared_ptr<Node> root = std::make_shared<Node> (Node(vec[0]));
  int count = 1;

  std::queue<std::shared_ptr<Node>> q;
  q.push(root);
  while (!q.empty()) {
    std::shared_ptr<Node> current = q.front();
    q.pop();

    if (count < (int)vec.size() && current->left == nullptr) {
      if (vec[count] != -1) {
        current->left = std::make_shared<Node> (Node(vec[count++]));
        q.push(current->left);
      }
      else{
        count++;
      }
    }

    if (count < (int)vec.size() && current->right == nullptr) {
      if (vec[count] != -1) {
        current->right = std::make_shared<Node> (Node(vec[count++]));
        q.push(current->right);
      }
      else{
        count++;
      }
    }
  }
    return root;
}

// Function to level order traversal of the tree
void TravLvlOrd(std::shared_ptr<Node> root) {
  std::queue<std::shared_ptr<Node>> qq;
  qq.push(root);

  while (!qq.empty()) {
    std::shared_ptr<Node> node = qq.front();
    qq.pop();
    std::cout << "--------------" << std::endl;
    std::cout << "Current node: " << node->value << std::endl;

    if (node->left != nullptr) {
      std::cout << "Left-child: " << node->left->value << std::endl;
      qq.push(node->left);
    }
    else{
      std::cout << "Left-child: NULL" << std::endl;
    }

    if (node->right != nullptr) {
      std::cout << "Right-child: " << node->right->value << std::endl;
      qq.push(node->right);
    }
    else{
      std::cout << "Right-child: NULL" << std::endl;
    }
    std::cout << "--------------" << std::endl;
  }
}

#endif // UTILS_H
