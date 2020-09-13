#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
public:
  int value;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;
  TreeNode(int value) {
    this->value = value;
  }
};

class Tree {
public:
  TreeNode* root;

  Tree() {
    root = nullptr;
  }

  TreeNode* BuildTree (std::vector<int>& vec) {
    this->root = new TreeNode(vec[0]);

    std::queue<TreeNode*> q;
    q.push(this->root);

    int i = 1;
    while (!q.empty()) {
      TreeNode* current = q.front();
      q.pop();

      if (current->left == nullptr && i < vec.size()) {
        if (vec[i] != -1) {
          current->left = new TreeNode(vec[i++]);
          q.push(current->left);
        }
        else {
          i++;
        }
      }

      if (current->right == nullptr && i < vec.size()) {
        if (vec[i] != -1) {
          current->right = new TreeNode(vec[i++]);
          q.push(current->right);
        }
        else {
          i++;
        }
      }
    }
    std::cout << "Tree building complete" << std::endl;
    return root;
  }

  void TraverseBFS() {
    std::cout << "Traversing tree in BFS order" << std::endl;
    std::queue<TreeNode*> q;
    q.push(this->root);

    TreeNode* current;
    while (!q.empty()) {
      current = q.front();
      q.pop();

      std::cout << "--------------------" << std::endl;
      std::cout << "Current Node: " << current->value << std::endl;

      if (current->left != nullptr) {
        q.push(current->left);
        std::cout << "Left child: " << current->left->value << std::endl;
      }
      else {
        std::cout << "Left child: nullptr" << std::endl;
      }

      if (current->right != nullptr) {
        q.push(current->right);
        std::cout << "Right child: " << current->right->value << std::endl;
      }
      else {
        std::cout << "Right child: nullptr" << std::endl;
        std::cout << "--------------------" << std::endl;
      }
    }
  }

  void delNodes(TreeNode* node) {
    if (node == nullptr) {
      return;
    }

    delNodes(node->left);
    delNodes(node->right);

    delete node;
  }

  ~Tree() {
    std::cout << "Destructor called" << std::endl;
    delNodes(this->root);  // delete nodes using DFS traversal
  }

};

int main (int argc, char** argv) {
  std::vector<int> vec = {1,2,3,4};

  // Build tree
  Tree* mytree = new Tree();
  mytree->BuildTree(vec);
  mytree->TraverseBFS();

  delete mytree;

  return 0;
}
