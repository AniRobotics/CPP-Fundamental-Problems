/*
Given an array of linked-lists lists, each linked list is sorted in ascending order.

Merge all the linked-lists into one sort linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/

/*
Use a min-heap (priority_queue in C++) and throw all the elements of each of the lists into it. When you
pop the elements from the heap, they will will popped in sorted order.
*/

#include <iostream>
#include <memory>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
  int value;
  std::shared_ptr<Node> next;
  Node(int value) {this->value = value;}
};

std::shared_ptr<Node> buildLinedList(const std::vector<int>& vec) {
  std::shared_ptr<Node> head = std::make_shared<Node> (Node(vec[0]));
  std::shared_ptr<Node> current = head;

  for (size_t i = 1; i < vec.size(); i++) {
    current->next = std::make_shared<Node> (Node(vec[i]));
    current = current->next;
  }

  return head;
}

int main (int argc, char** argv) {
  // Build the vector of linked lists
  std::vector<std::shared_ptr<Node>> vecLL;
  vecLL.push_back(buildLinedList(std::vector<int> ({1,4,5})));
  vecLL.push_back(buildLinedList(std::vector<int> ({1,3,4})));
  vecLL.push_back(buildLinedList(std::vector<int> ({2,6})));

  // Create a min-heap using priority_queue
  auto cmp = [](int first, int second){return first > second;};
  std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);

  // Throw all the node values into the min-heap
  for (std::shared_ptr<Node> ll : vecLL) {
    std::shared_ptr<Node> curr = ll;
    while (curr != nullptr) {
      pq.push(curr->value);
      curr = curr->next;
    }
  }

  // Print the elements of the min-heap
  std::shared_ptr<Node> resHead = std::make_shared<Node> (Node(pq.top()));
  pq.pop();
  std::shared_ptr<Node> resCurr = resHead;
  while (!pq.empty()) {
    // std::cout << pq.top() << std::endl;
    resCurr->next = std::make_shared<Node> (Node(pq.top()));
    pq.pop();
    resCurr = resCurr->next;
  }

  // Print the resulting  linked list
  std::shared_ptr<Node> res = resHead;
  while (res != nullptr) {
    std::cout << res->value << "->";
    res = res->next;
  }
  std::cout << "nullptr" << std::endl;

  return 0;
}
