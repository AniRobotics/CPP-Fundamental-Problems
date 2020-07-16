#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/*
This code shows how to create, traverse and reverse a singly linked list.
This also introduces concept of smart-pointer while creating new nodes.
This code shows how to iterate over a vector array using iterator pointer.
*/

class Node {
public:
  Node(int value) {
    this->value = value;
  }
  int value;
  std::shared_ptr<Node> next;
};

void BuildLinkedListManually() {
  std::cout << "\nInside Function BuildLinkedListManually()" << std::endl;

  // Create the head of a LinkedList
  std::shared_ptr<Node> head = std::make_shared<Node> (Node(5));

  // Create a LinkedList manually
  head->next = std::make_shared<Node> (Node(10));
  head->next->next = std::make_shared<Node> (Node(15));

  // Print the node values manually
  std::cout << head->value << "," << head->next->value << "," << head->next->next->value << std::endl;
  std::cout << "----------------------" << std::endl;
}

std::shared_ptr<Node> BuildLinkedListIteratively(std::vector<int>& NodeVals) {
  std::cout << "Inside Function BuildLinkedListIteratively()" << std::endl;
  std::shared_ptr<Node> Head;
  std::shared_ptr<Node> CurrentNode;
  for (auto it = NodeVals.begin(); it != NodeVals.end(); it++) {
    if (CurrentNode != nullptr) {
      CurrentNode->next = std::make_shared<Node> (Node(*it));
      CurrentNode = CurrentNode->next;
    }
    else {
      Head = std::make_shared<Node> (Node(*it));
      CurrentNode = Head;
    }
  }
  std::cout << "Linked List building completed." << std::endl;
  std::cout << "----------------------" << std::endl;
  return Head;
}

void TraverseLinkedList(std::shared_ptr<Node> CurrentNode){
  std::cout << "Inside Function TraverseLinkedList()" << std::endl;
  while (CurrentNode != nullptr) {
    std::cout << CurrentNode->value << ",";
    CurrentNode = CurrentNode->next;
  }
  std::cout << "\n---------------------------\n" << std::endl;
}

std::shared_ptr<Node> ReverseLinkedList(std::shared_ptr<Node> CurrentNode) {
  std::cout << "Inside Function ReverseLinkedList()" << std::endl;
  std::shared_ptr<Node> NewHead;
  std::shared_ptr<Node> Previous;
  while (CurrentNode != nullptr) {
    if (Previous != nullptr) {
      NewHead = std::make_shared<Node> (Node(CurrentNode->value));
      NewHead->next = Previous;
      Previous = NewHead;
    }
    else {
      Previous = std::make_shared<Node> (Node(CurrentNode->value));
    }
    CurrentNode = CurrentNode->next;
  }
  std::cout << "Linked List Reversed" << std::endl;
  std::cout << "\n---------------------------\n" << std::endl;
  return NewHead;}


int main (int argc, char** argv) {
  // Build LinkedList Manually
  BuildLinkedListManually();

  // Build and Traverse LinkedList Iteratively
  std::vector<int> NodeVals = {20,25,30,35};
  std::shared_ptr<Node> Head = BuildLinkedListIteratively(NodeVals);
  TraverseLinkedList(Head);

  // Reverse a Linked List
  std::shared_ptr<Node> ReversedHead = ReverseLinkedList(Head);
  TraverseLinkedList(ReversedHead);

  return 0;
}
