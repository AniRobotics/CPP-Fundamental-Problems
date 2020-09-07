/*
The graph we will be preparing would look like as foollowing
A -------------- B
|                |
|                |
C----------------D
*/

#include <iostream>
#include <unordered_map>
#include "Utils.h"

using namespace std;

std::shared_ptr<Node> BuildGraph() {
  // Create Nodes
  std::shared_ptr<Node> nodeA = std::make_shared<Node> (Node(1));
  std::shared_ptr<Node> nodeB = std::make_shared<Node> (Node(2));
  std::shared_ptr<Node> nodeC = std::make_shared<Node> (Node(3));
  std::shared_ptr<Node> nodeD = std::make_shared<Node> (Node(4));

  // Create neighbors
  nodeA->neighbor.push_back(nodeB);
  nodeA->neighbor.push_back(nodeD);

  nodeB->neighbor.push_back(nodeA);
  nodeB->neighbor.push_back(nodeC);

  nodeC->neighbor.push_back(nodeB);
  nodeC->neighbor.push_back(nodeD);

  nodeD->neighbor.push_back(nodeA);
  nodeD->neighbor.push_back(nodeC);

  return nodeA;
}

int main(int argc, char** argv) {
  // Create a graph and get one of the node of
  // the connected graph
  std::shared_ptr<Node> nodeA = BuildGraph();

  // Traverse teh graph
  // TraverseGraph(nodeA);

  // Start cloning the given graph
  std::unordered_map<int, std::shared_ptr<Node>> hmap;
  std::set<int> visited;
  std::queue<std::shared_ptr<Node>> q;
  q.push(nodeA);

  // Starting node of the cloned graph
  std::shared_ptr<Node> tempA = std::make_shared<Node> (Node(nodeA->value));
  hmap[nodeA->value] = tempA;
  cout << "======================" << std::endl;
  while (!q.empty()) {
    std::shared_ptr<Node> currentNode = q.front();
    q.pop();

    if (visited.find(currentNode->value) == visited.end()) {
      std::shared_ptr<Node> tempCurrent = hmap[currentNode->value];
      for (auto n : currentNode->neighbor) {
        if (hmap.find(n->value) == hmap.end()) {
          std::shared_ptr<Node> tempNew = std::make_shared<Node> (Node(n->value));
          tempCurrent->neighbor.push_back(tempNew);
          hmap[n->value] = tempNew;
        }
        else{
          tempCurrent->neighbor.push_back(hmap[n->value]);
        }
        q.push(n);
      }
    }
    // Check the currentNode as visited
    visited.insert(currentNode->value);
  }

  std::cout << "All the node in the graph are visited" << std::endl;
  cout << "======================" << std::endl;

  // Traverse the cloned graph
  TraverseGraph(tempA);

  return 0;
}
