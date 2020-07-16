#include <iostream>
#include <vector>
#include <queue>
#include <memory>

using namespace std;

/*
                60
              /   \
            50     70      <----- Tree used for this problem
          /   \  /   \
        40    55 65   80
Find lowest common ancestor for the nodes 70 and 80
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

std::shared_ptr<Node> find_lowest_cmn_ancestor(std::shared_ptr<Node> node, int p, int q) {
  if (node->get_value() < p && node->get_value() < q) {
    return find_lowest_cmn_ancestor(node->get_right(), p, q);
  }
  else if (node->get_value() > p && node->get_value() > q) {
    std::cout << "Both are greater than the current node value" << std::endl;
    return find_lowest_cmn_ancestor(node->get_left(), p, q);
  }
  else{
    return node;
  }
}

int main (int argc, char** argv) {
  // Build the tree
  std::vector<int> node_val = {60, 50, 70, 40, 55, 65, 80};
  std::shared_ptr<Node> root = build_btree(node_val);

  // Elements for which lowest common ancestor to find
  int p = 65, q = 80;

  // Find depth of binary tree
  std::shared_ptr<Node> ancester_node = find_lowest_cmn_ancestor(root, p, q);
  std::cout << "Lowest common ancestor node: " << ancester_node->get_value() << std::endl;

  return 0;
}
