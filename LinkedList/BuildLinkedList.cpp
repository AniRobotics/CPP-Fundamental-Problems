#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
  int value;
  Node* next = nullptr;
  Node(int value) {
    this->value = value;
  }
};

class LinkedList{
public:
  Node* head;
  LinkedList() {
    head = nullptr;
  }

  void BuildLinkdList(std::vector<int>& vec) {
    head = new Node(vec[0]);
    Node* current = head;
    for (size_t i = 1; i < vec.size(); i++) {
      current->next = new Node(vec[i]);
      current = current->next;
    }
    std::cout << "Linked List building completed" << std::endl;
  }

  void TraverseLinkedList() {
    Node* current = this->head;
    while (current != nullptr) {
      std::cout << current->value << "->";
      current = current->next;
    }
    std::cout << "nullptr" << std::endl;
  }

  void delNodes(Node* node) {
    if (node == nullptr) {
      return;
    }
    delNodes(node->next);
    delete node;
  }

  ~LinkedList() {
    std::cout << "Linked list destructor called" << std::endl;
    delNodes(this->head);
  }
};

int main(int argc, char** argv) {
  std::vector<int> vec = {1,2,3,4,5,6};

  LinkedList* ll = new LinkedList();
  ll->BuildLinkdList(vec);
  ll->TraverseLinkedList();

  delete ll;

  return 0;
}
