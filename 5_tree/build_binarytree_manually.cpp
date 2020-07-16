#include <iostream>
#include <queue>
#include <memory>

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

int main(int argc, char** argv) {
  std::cout << "binary tree building" << std::endl;

  // Manually build a tree
  std::shared_ptr<Node> root = std::make_shared<Node> (Node(10));
  root->set_left(20);
  root->set_right(30);
  root->get_left()->set_left(40);
  root->get_left()->set_right(50);

  // Print the node values of the tree built manually
  std::cout << root->get_value() << std::endl;
  std::cout << root->get_left()->get_value() << " , " << root->get_right()->get_value() << std::endl;
  std::cout << root->get_left()->get_left()->get_value() << " , " << root->get_left()->get_right()->get_value() << std::endl;

  return 0;
}
