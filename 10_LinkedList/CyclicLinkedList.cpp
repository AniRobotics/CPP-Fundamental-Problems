#include "LinkedList.h"
#include <vector>

using namespace std;

int main (int argc, char** argv) {
  // // Build cyclic linkedlist manually
  // std::shared_ptr<Node> root = std::make_shared<Node> (Node(4));
  // root->next = std::make_shared<Node> (Node(7));
  // root->next->next = root;
  //
  // // Print cyclic linkedlist manually
  // std::cout << root->value << std::endl;
  // std::cout << root->next->value << std::endl;
  // std::cout << root->next->next->value << std::endl;
  // std::cout << root->next->next->next->value << std::endl;
  // std::cout << root->next->next->next->next->value << std::endl;

  // Build cyclic linkedlist iteratively
  std::vector<int> vec = {1,2,3,4,5,6,7,8};
  std::shared_ptr<Node> root;
  std::shared_ptr<Node> currentNode;
  int count = 0;

  while (count < (int)vec.size()) {
    if (root == nullptr) {
      root = std::make_shared<Node> (Node(vec[count++]));
      currentNode = root;
    }
    currentNode->next = std::make_shared<Node> (Node(vec[count++]));
    currentNode = currentNode->next;
  }
  // Make the next of the last node pointing to the root, to make
  // a cyclic linked list
  currentNode->next = root;

  // Traverse the linkedlist
  int counter = 0;
  std::shared_ptr<Node> travCurrent = root;

  while (travCurrent != nullptr && counter < (int)3*vec.size()) {
    std::cout << travCurrent->value << std::endl;
    travCurrent = travCurrent->next;
    counter++;
  }

  // Detect loop in a Linked List
  std::shared_ptr<Node> slowPtr = root, fastPtr = root;
  while (slowPtr != nullptr && fastPtr != nullptr) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    std::cout << "-------------------------" << std::endl;
    std::cout << "Slow: " << slowPtr->value << "," << "Fast: " << fastPtr->value << std::endl;

    if (slowPtr == fastPtr) {
      std::cout << "loop detected at the element: " << slowPtr->value << std::endl;
      break;
    }
  }

  return 0;
}
