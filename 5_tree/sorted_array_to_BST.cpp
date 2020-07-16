#include <iostream>
#include <memory>
#include <vector>

using namespace std;

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

void build_BST(std::shared_ptr<Node> node, int node_vals[], int left, int right) {
  if (left <= right) {
    int mid_used = (left + right) / 2;
    int left_node_index = (left + mid_used - 1) / 2;
    int right_node_index = (mid_used + 1 + right) / 2;

    if (left_node_index > 0 && left_node_index < mid_used) {
      node->set_left(node_vals[left_node_index]);
      build_BST(node->get_left(), node_vals, left, mid_used - 1);
    }

    if (mid_used < right_node_index) {
      node->set_right(node_vals[right_node_index]);
      build_BST(node->get_right(), node_vals, mid_used + 1, right);
    }
  }
}

int main (int argc, char** argv) {

  // Setup
  int num_ele = 7;
  int node_val[num_ele] = {40, 50, 55, 60, 65, 70, 80};
  int mid = num_ele / 2;
  std::shared_ptr<Node> root = std::make_shared<Node> (Node(node_val[mid]));

  // Call build_BST
  build_BST(root, node_val, 0, num_ele-1);

  return 0;
}
