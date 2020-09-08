/*
Given two non-empty binary trees s and t, check whether tree t has exactly
the same structure and node values with a subtree of s. A subtree of s is a tree
consists of a node in s and all of this node's descendants. The tree s could
also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree
of s.


Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
*/

#include "Utils.h"

using namespace std;

bool isSameTree(std::shared_ptr<Node> s, std::shared_ptr<Node> t) {
  if (s == nullptr && t == nullptr) {
    return true;
  }
  else if (s == nullptr && t != nullptr) {
    return false;
  }
  else if (s != nullptr && t == nullptr) {
    return false;
  }
  std::cout << "[" << s->value << "," << t->value << "]" << std::endl;
  return (s->value == t->value)
         && isSameTree(s->left,t->left)
         && isSameTree(s->right,t->right);
}

bool isSubTree(std::shared_ptr<Node> s, std::shared_ptr<Node> t) {
  if (s == nullptr && t == nullptr) {
    return true;
  }
  else if (s == nullptr && t != nullptr) {
    return false;
  }
  else if (s != nullptr && t == nullptr) {
    return false;
  }
  else if (isSameTree(s,t)) {
    return true;
  }
  return isSubTree(s->left,t) || isSubTree(s->right,t);
}

int main(int argc, char** argv) {
  std::vector<int> vec1 = {3,4,5,1,2,-1,-1,-1,-1,0};
  std::vector<int> vec2 = {4,1,2};

  // Build the two trees
  std::shared_ptr<Node> sRoot = BuildTree(vec1);
  std::shared_ptr<Node> tRoot = BuildTree(vec2);

  bool ans = isSubTree(sRoot,tRoot);

  if (ans) {
    std::cout << "One tree is a subtree to the another" << std::endl;
  }
  else {
    std::cout << "The trees are not subtree of the other" << std::endl;
  }

  return 0;
}
