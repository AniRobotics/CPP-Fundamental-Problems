#include "LinkedList.h"

void LinkedList::insert(int val){
    shared_ptr<Node> new_node =  make_shared<Node>(val);
    
    // If head is NULL-PTR
    if (head == nullptr) {
        head = new_node;
        return;
    }
    
    // Traverse until the end, then insert
    shared_ptr<Node> current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = new_node;
}

void LinkedList::print(){
    shared_ptr<Node> current = head;
    while (current != nullptr) {
        cout << current->value << ", ";
        current = current->next;
    }
    cout << endl;
}


