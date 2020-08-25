#ifndef TREE_UTILS_H
#define TREE_UTILS_H

#include <iostream>
#include <memory>
#include <vector>
#include <queue>

class Node {
public:
  int value;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
  Node(int value) {this->value = value;}
};


// Function to build a binary tree by performing level order traversal
std::shared_ptr<Node> BuildTree(std::vector<int>& nodeVals) {
  std::shared_ptr<Node> root = std::make_shared<Node> (Node(nodeVals[0]));
  
  std::queue<std::shared_ptr<Node>> q;
  q.push(root);

  int count = 1;
  while (!q.empty() && count < nodeVals.size()) {
    std::shared_ptr<Node> temp = q.front();
    q.pop();
    
    if (temp->left == nullptr && count < nodeVals.size()) {
      temp->left = std::make_shared<Node> (Node(nodeVals[count++]));
      q.push(temp->left);
    }

    if (temp->right == nullptr && count < nodeVals.size()) {
      temp->right = std::make_shared<Node> (Node(nodeVals[count++]));
      q.push(temp->right);
    }
  }

  return root;
}

// Function to print the node values of the binary tree by level order traversal
void PrintTree(std::shared_ptr<Node> root) {
  std::queue<std::shared_ptr<Node>> q;
  q.push(root);

  std::cout << "------------------" << std::endl;
  std::cout << "root: " << root->value << std::endl;
  std::cout << "------------------" << std::endl;

  while(!q.empty()) {
    std::shared_ptr<Node> temp = q.front();
    q.pop();
    
    if (temp->left != nullptr) {
      q.push(temp->left);
      std::cout << "-------------------" << std::endl;
      std::cout << "parent: " << temp->value << std::endl;
      std::cout << "leftChild: " << temp->left->value << std::endl;
      std::cout << "-------------------" << std::endl;
    }

    if (temp->right != nullptr) {
      q.push(temp->right);
      std::cout << "-------------------" << std::endl;
      std::cout << "parent: " << temp->value << std::endl;
      std::cout << "rightChild: " << temp->right->value << std::endl;
      std::cout << "-------------------" << std::endl;
    }
  }
}

/*
  // Build tree manually
  std::shared_ptr<Node> root = std::make_shared<Node> (Node(1));
  root->left = std::make_shared<Node> (Node(2));
  root->right = std::make_shared<Node> (Node(3));

  root->left->left = std::make_shared<Node> (Node(4));
  root->left->right = std::make_shared<Node> (Node(5));

  root->right->left = std::make_shared<Node> (Node(6));
  root->right->right = std::make_shared<Node> (Node(7));
  
  // Print tree nodes
  std::cout << root->value << std::endl;
  std::cout << root->left->value << "," << root->right->value << std::endl;
  std::cout << root->left->left->value << "," << root->left->right->value << "," << root->right->left->value << "," << root->right->right->value << std::endl;*/

#endif // TREE_UTILS_H
