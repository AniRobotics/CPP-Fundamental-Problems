/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

#include "LinkedList.h"
#include "Utils.h"

int main (int rgc, char** argv) {
  std::vector<int> vec = {1,2,3,4,5};
  int k = 2;

  // Build and print the Linked List
  std::shared_ptr<Node> head = buildLinkedList(vec);
  PrintLinkedList(head);

  // Remove the k^{th} from the end of the linked list
  std::cout << "Remove the k^{th} node from the linked list" << std::endl;
  std::shared_ptr<Node> slow = head, fast=head;

  // Move the fast pointer K nodes ahead of the slow pointer
  for (int i = 0; i <= k; i++) {
    fast = fast->next;
  }

  while (fast != nullptr) {
    fast = fast->next;
    slow = slow->next;
  }

  // At this point fast has hit the end and slow is k node behind the end
  slow->next = slow->next->next;

  // Traverse the modified Linked List
  std::shared_ptr<Node> travCurrent = head;
  while (travCurrent != nullptr) {
    std::cout << travCurrent->value << std::endl;
    travCurrent = travCurrent->next;
  }

  return 0;
}
