#ifndef UTILS_H
#define UTILS_H

#include <vector>

std::shared_ptr<Node> buildLinkedList(std::vector<int>& vec) {
  // Build the Linked List
  std::shared_ptr<Node> head;
  std::shared_ptr<Node> currentNode;
  for (int n : vec) {
    if (head== nullptr) {
      head = std::make_shared<Node> (Node(n));
      currentNode = head;
      continue;
    }
    currentNode->next = std::make_shared<Node> (Node(n));
    currentNode = currentNode->next;
  }
  return head;
}

// Traverse the Linked List
void PrintLinkedList(std::shared_ptr<Node> head) {
  std::shared_ptr<Node> travCurrent = head;

  while (travCurrent != nullptr) {
    std::cout << travCurrent->value << std::endl;
    travCurrent = travCurrent->next;
  }
}

#endif // UTILS_H
