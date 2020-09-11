/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

#include <iostream>

using namespace std;

class TrieNode {
public:
  TrieNode* links[26];
  bool isEnd;
  TrieNode() {
    for (int i = 0; i < 26; i++) {
      links[i] = nullptr;
    }
    isEnd = false;
  }
  bool exists(char c) { return this->links[c - 'a'] != nullptr; }
};

class Trie {
public:
  TrieNode* root;
  Trie() { root = new TrieNode(); }
  TrieNode* get(char c) { return root->links[c - 'a']; }
  void insert (string word) {
    TrieNode* current = root;
    for (char c : word) {
      if (!current->exists(c)) {
        current->links[c - 'a'] = new TrieNode();
      }
      current = current->links[c - 'a'];
    }
    current->isEnd = true;
  }

  TrieNode* searchWord(string word) {
    TrieNode* current = root;
    for (char c : word) {
      if (!current->exists(c)) {
        return nullptr;
      }
      current = current->links[c - 'a'];
    }
    return current;
  }

  bool wordExists(string word) {
    TrieNode* node = searchWord(word);
    return node->isEnd == true;
  }

  bool prefixExists(string prefix) {
    TrieNode* node = searchWord(prefix);

    return node != nullptr && node->isEnd;
  }

  bool startWith(string prefix) {
    TrieNode* node = searchWord(prefix);

    return node != nullptr && !node->isEnd;
  }

  void delNodes(TrieNode* node) {
    if (node == nullptr) { return; }
    for (int i = 0; i < 26; i++) {
      if (node->links[i] != nullptr) {
         delNodes(node->links[i]);
         std::cout << "deleting one node at index " << i << " of link array" << std::endl;
      }
    }
    delete node;
  }

  ~Trie() {
    std::cout << "\n\nDestructor of Trie class is called" << std::endl;
    delNodes(this->root);
    std::cout << "All nodes in the heap are destroied\n\n" << std::endl;
  }

};

int main(int argc, char** argv) {
  Trie* obj = new Trie();
  obj->insert("apple");

  obj->wordExists("apple") ? std::cout << "TRUE\n" : std::cout << "FALSE\n";
  obj->prefixExists("app") ? std::cout << "TRUE\n" : std::cout << "FALSE\n";
  obj->startWith("app") ? std::cout << "TRUE\n" : std::cout << "FALSE\n";

  delete obj;
  return 0;
}
