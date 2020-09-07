#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <memory>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Node {
public:
  int value;
  std::vector<std::shared_ptr<Node>> neighbor;
  Node () {}
  Node(int value) {this->value = value;}
};

void TraverseGraph(std::shared_ptr<Node> node) {
  // Start traversing the graph
  std::set<int> visited;
  std::queue<std::shared_ptr<Node>> q;
  q.push(node);

  cout << "======================" << std::endl;
  while (!q.empty()) {
    std::shared_ptr<Node> currentNode = q.front();
    q.pop();

    if (visited.find(currentNode->value) == visited.end()) {
      std::cout << "Exploring node: " << currentNode->value << std::endl;
      std::cout << "neighbors: ";
      for (auto n : currentNode->neighbor) {
        std::cout << n->value << ",";
        q.push(n);
      }
      std::cout << "\n-----------------" << std::endl;
    }
    else {
      std::cout << currentNode->value << " was visited before" << std::endl;
      std::cout << "-----------------" << std::endl;
    }
    // Check the currentNode as visited
    visited.insert(currentNode->value);
  }

  std::cout << "All the node in the graph are visited" << std::endl;
  cout << "======================" << std::endl;
}

#endif //UTILS_H
