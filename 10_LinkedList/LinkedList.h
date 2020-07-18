#include <iostream>
#include <memory>

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Node structure of LinkedList
struct Node {
    Node(int value) {Node::value = value;}
    int value;
    shared_ptr<Node> next;
};

// Linked List class with basic functionality
class LinkedList{
public:
    LinkedList(){}
    shared_ptr<Node> get_head() {return head;}
    void set_head(shared_ptr<Node>& head) {LinkedList::head = head;}
    void insert(int value);
    void print();
private:
    shared_ptr<Node> head;
};

#endif /* LINKEDLIST_H */
