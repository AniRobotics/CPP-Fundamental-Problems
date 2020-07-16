#include <iostream>
#include <vector>
#include <queue>
#include <memory>

using namespace std;

/*
                10
              /   \
            20     20      <----- Tree used for this problem
          /   \  /   \
        40    50 50   40
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

std::shared_ptr<Node> build_btree(std::vector<int> node_vals) {
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

  return std::move(root);
}

bool is_symmetric(std::shared_ptr<Node> left, std::shared_ptr<Node> right) {
  if (left == nullptr && right != nullptr) {
    return false;
  }
  if (left != nullptr && right == nullptr) {
    return false;
  }
  if (left == nullptr && right == nullptr) {
    return true;
  }
  if (left->get_value() != right->get_value()) {
    return false;
  }
  return (left->get_value() == right->get_value()) && is_symmetric(left->get_left(),right->get_right()) && is_symmetric(left->get_right(),right->get_left());
}

int main (int argc, char** argv) {
  // Build the tree
  std::vector<int> node_val = {10, 20, 20, 40, 50, 50, 40};
  // std::vector<int> node_val = {10};
  std::shared_ptr<Node> root = build_btree(node_val);

  // Find depth of binary tree
  bool symmetric = is_symmetric(root->get_left(), root->get_right());
  std::cout << "symmetric tree: " << ((symmetric) ? "True" : "False") << std::endl;

  return 0;
}
