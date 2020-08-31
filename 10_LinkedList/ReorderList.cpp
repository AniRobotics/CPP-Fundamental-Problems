/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

#include "LinkedList.h"
#include "Utils.h"
#include <stack>

using namespace std;

int main (int argc, char** argv) {
  std::vector<int> vec = {1,2,3,4,5,6};

  // Build and Print the linked list
  std::shared_ptr<Node> head = buildLinkedList(vec);
  PrintLinkedList(head);

  // Traverse the linked list and push the nodes into the stack
  std::stack<std::shared_ptr<Node>> stk;
  std::shared_ptr<Node> currentNode = head;

  while (currentNode != nullptr) {
    stk.push(currentNode);
    currentNode = currentNode->next;
  }

  std::shared_ptr<Node> tempNode = head;
  int count = 0;
  while (count <= (int)stk.size()/2) {
    std::shared_ptr<Node> insertNode = stk.top();
    stk.pop();

    insertNode->next = tempNode->next;
    tempNode->next = insertNode;
    tempNode = tempNode->next->next;

    // std::cout << "count: " << count << std::endl;
    // std::cout << tempNode->value << std::endl;
    // std::cout << tempNode->next->value << std::endl;
    // std::cout << tempNode->next->next->value << std::endl;
    // std::cout << tempNode->next->next->next->value << std::endl;

    count++;
  }
  // std::cout << tempNode->value << std::endl;
  // at this point the last node will be pointing to itself.
  // So we need to make the next of this node to be nullptr
  tempNode->next = nullptr;

  std::cout << "---------------------------" << std::endl;
  std::cout << "Desired linked list" << std::endl;
  PrintLinkedList(head);

  return 0;
}
