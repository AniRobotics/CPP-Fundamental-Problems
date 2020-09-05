/*
The graph we will be preparing would look like as foollowing
A -------------- B
|                |
|                |
C---------------D
*/

#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

template <typename T>
class Node {
public:
  T value;
  std::vector<std::shared_ptr<Node<T>>> neighbor;
  Node () {}
  Node(T value) {this->value = value;}
};

int main(int argc, char** argv) {
  // Create Nodes
  std::unique_ptr<Node<std::string>> nodeA(new Node<std::string>("A")); // = std::make_shared<Node<std::string>> (Node<std::string>("A"));
  std::unique_ptr<Node<std::string>> nodeB(new Node<std::string>("B"));
  std::unique_ptr<Node<std::string>> nodeC(new Node<std::string>("C"));
  std::unique_ptr<Node<std::string>> nodeD(new Node<std::string>("D"));

  // Create neighbors
  nodeA->neighbor.push_back(nodeB);
  // nodeA->neighbor.push_back(nodeD);
  //
  // nodeB->neighbor.push_back(nodeA);
  // nodeB->neighbor.push_back(nodeC);
  //
  // nodeC->neighbor.push_back(nodeB);
  // nodeC->neighbor.push_back(nodeD);
  //
  // nodeD->neighbor.push_back(nodeA);
  // nodeD->neighbor.push_back(nodeC);

  // // Start traversing the graph
  // std::set<std::string> visited;
  // std::queue<std::shared_ptr<Node<std::string>>> q;
  // q.push(nodeA);
  //
  // while (!q.empty()) {
  //   std::shared_ptr<Node<std::string>> currentNode = q.front();
  //   q.pop();
  //   visited.insert(currentNode->value);
  //
  //   if (visited.find(currentNode->value) == visited.end()) {
  //     std::cout << "Exploring node: " << currentNode->value << std::endl;
  //     std::cout << "Children: " << std::endl;
  //     for (auto n : currentNode->neighbor) {
  //       std::cout << n->value << ",";
  //       q.push(n);
  //     }
  //     std::cout << "-----------------" << std::endl;
  //   }
  //   else {
  //     std::cout << currentNode->value << " was visited before" << std::endl;
  //   }
  // }

  return 0;
}
