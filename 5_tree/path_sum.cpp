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

bool path_sum_exists(std::shared_ptr<Node> node, int target, std::vector<int> path) {
  if (target < 0 || node == nullptr) {
    return false;
  }

  if (target-node->get_value() == 0 && node->get_left() == nullptr && node->get_right() == nullptr) {
    path.push_back(node->get_value());
    for (auto i = path.begin(); i != path.end(); i++) {
      std::cout << *i << ",";
    }
    std::cout << std::endl;
    return true;
  }

  path.push_back(node->get_value());
  return path_sum_exists(node->get_left(), target-node->get_value(), path) || path_sum_exists(node->get_right(), target-node->get_value(), path);
}

int main (int argc, char** argv) {
  // Build the tree
  std::vector<int> node_val = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  std::shared_ptr<Node> root = build_btree(node_val);

  // Find if the sum exists (on a path from root to a leaf)
  int target = 160;
  std::vector<int> store_path;
  bool exists = path_sum_exists(root, target, store_path);
  std::cout << "Path sum exists: " << ((exists) ? "Yes" : "No") << std::endl;

  return 0;
}
