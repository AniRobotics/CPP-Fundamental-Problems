#include <iostream>

using namespace std;

// NODE structure
struct Node{
  Node *next = NULL;
  int value = 0;
};

// LINKEDLIST class
class LinkedList{
private:
  Node *head = NULL;
  int num_elements = 0;
public:
  bool insert(const int &val);
  bool insert_at(const int &val, const int &ind);
  void print_node_values();
  void free_memory(Node *node);
  ~LinkedList();
};

// Method to INSERT node
bool LinkedList::insert(const int &val){
  Node *new_node = new Node;
  new_node->value = val;
  num_elements += 1;

  if (head == NULL) {
    head = new_node;
    return true;
  }

  Node *current_node = head;
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }
  current_node->next = new_node;
  return true;
}

bool LinkedList::insert_at(const int &val, const int &ind){
  Node *new_node = new Node;
  new_node->value = val;

  int count = 0;
  Node* current_node = head;
  while (count < ind-1) {
    current_node = current_node->next;
    count++;
  }
  Node* next_node = current_node->next;

  // insert now
  current_node->next = new_node;
  new_node->next = next_node;
}

// Method to traverse the linkedlist and print node values
void LinkedList::print_node_values(){
  Node *current_node = head;
  while (current_node != NULL) {
    std::cout << "node value = " << current_node->value << std::endl;
    current_node = current_node->next;
  }
  std::cout << "----------------------" << std::endl;
}

// Free memory
void LinkedList::free_memory(Node *node){
  if (node == NULL) {
    return;
  }
  free_memory(node->next);
  delete node;
  std::cout << "node memory recovered" << std::endl;
  return;
}

// Destructor
LinkedList::~LinkedList(){
  free_memory(head);
}

int main() {
  // Create a linkedlist on the heap
  LinkedList* ll = new LinkedList();

  // Array containing node values to be inserted
  int node_val_arr[] = {10, 20, 30, 40, 50};

  // Insert node values to the linkedlist
  for (auto i = 0; i < sizeof(node_val_arr)/sizeof(node_val_arr[0]); i++) {
    ll->insert(node_val_arr[i]);
  }

  // Check whether node values are inserted properly
  ll->print_node_values();

  // Insert a node value at a given index
  int new_value = 25;
  int insert_index = 2;
  ll->insert_at(new_value, insert_index);

  // print the node values again
  ll->print_node_values();

  // regain the memory alloted to the nodes
  delete ll;

  return 0;
}
