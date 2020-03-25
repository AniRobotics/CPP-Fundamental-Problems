#include "LinkedList.h"

using namespace std;

shared_ptr<Node> reverse_LinkedList(LinkedList& ll){
    shared_ptr<Node> new_node = make_shared<Node>(ll.get_head()->value);
    shared_ptr<Node> prev = new_node;
    shared_ptr<Node> current = ll.get_head()->next;
    while (current != nullptr) {
        shared_ptr<Node> new_node = make_shared<Node>(current->value);
        new_node->next = prev;
        prev = new_node;
        current = current->next;
    }
    return prev;
}

int main(int argc, char** argv) {
    int value_array[10];
    
    // create data array with numbers
    cout << "Print values of the array" << endl;
    for (size_t i = 0; i < sizeof(value_array)/sizeof(value_array[0]); i++){
        value_array[i] = 2*i+1;
        cout << value_array[i] << ", ";
    }
    cout << endl;
    
    // Instantiate a Linked-List
    LinkedList ll = LinkedList();
    for (size_t i = 0; i < sizeof(value_array)/sizeof(value_array[0]); i++) {
        ll.insert(value_array[i]);
    }
    
    // Print node values of the linked list
    cout << "\nPrint values of the LinkedList" << endl;
    ll.print();
    
    // Reverse the LinkedList
    shared_ptr<Node> reversed_head = reverse_LinkedList(ll);
    
    // Create a new LinkedList and set its head to reversed_head
    LinkedList rl;
    rl.set_head(reversed_head);
    
    // Print values of the LinkedList
    cout << "\nPrint values of the reversed LinkedList" << endl;
    rl.print();    
    
    return 0;
}
