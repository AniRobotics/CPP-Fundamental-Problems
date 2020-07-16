#include <iostream>
#include <vector>
#include <queue>
#include <memory>

using namespace std;

/*
                10
              /   \
            20     30      <----- Tree used for this problem
          /   \  /   \
        40    50 60   70
      /
    80
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

void side_view(std::shared_ptr<Node> root) {
    std::queue<std::shared_ptr<Node>> q;
    q.push(root);

    std::shared_ptr<Node> current_node;
    int old_count = 1;
    int new_count = 0;
    while (!q.empty()) {
      for (int i = 0; i < old_count; i++) {
        current_node = q.front();
        q.pop();

        if (current_node->get_left() != nullptr) {
          q.push(current_node->get_left());
          new_count++;
        }

        if (current_node->get_right() != nullptr) {
          q.push(current_node->get_right());
          new_count++;
        }

        if (i == old_count -1) {
          std::cout << current_node->get_value() << std::endl;
        }
      }
      old_count = new_count;
      new_count = 0;
    }
}

int main (int argc, char** argv) {
  // Build the tree
  std::vector<int> node_val = {10, 20, 30, 40, 50, 60, 70, 80};
  std::shared_ptr<Node> root = build_btree(node_val);

  // Print side view of binary tree
  side_view(root);

  return 0;
}
