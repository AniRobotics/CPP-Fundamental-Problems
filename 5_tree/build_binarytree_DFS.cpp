#include <iostream>
#include <queue>
#include <memory>
#include <vector>

using namespace std;

/*
                10
              /   \
            20     30
          /   \  /   \
        40    50 60   70
      /  \
    80    90
*/

class Node {
private:
  int value;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
public:
  Node(int value) {this->value = value;}
  void set_left(int value) {left = std::make_shared<Node>(Node(value));}
  void set_right(int value) {right = std::make_shared<Node>(Node(value));}
  int get_value() { return value; }
  std::shared_ptr<Node> get_left() {return left;}
  std::shared_ptr<Node> get_right() {return right;}
};

void print_binarytree_DFS(std::shared_ptr<Node> node) {
  if (node != nullptr) {
    std::cout << node->get_value() << ", ";
    print_binarytree_DFS(node->get_left());
    print_binarytree_DFS(node->get_right());
  }
}

int main(int argc, char** argv) {
  std::cout << "binary tree building" << std::endl;

  // Values to be enterd into the tree
  std::vector<int> node_vals = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  // Build the tree
  int i = 0;
  std::shared_ptr<Node> root = std::make_shared<Node> (Node(node_vals[i++]));
  std::queue<std::shared_ptr<Node>> temp_q;
  temp_q.push(root);

  while (i < node_vals.size()) {
    auto current_parent = temp_q.front();
    temp_q.pop();

    if (current_parent->get_left() == nullptr) {
      current_parent->set_left(node_vals[i++]);
      temp_q.push(current_parent->get_left());
    }

    if (current_parent->get_right() == nullptr && i < node_vals.size()) {
      current_parent->set_right(node_vals[i++]);
      temp_q.push(current_parent->get_right());
    }
  }
  std::cout << "Tree building completed" << std::endl;

  // Print the node values of the tree in DFS order
  std::cout << "Printing using pre-order traversal: ";
  print_binarytree_DFS(root);
  std::cout << std::endl;

  return 0;
}
