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
#include <memory>

using namespace std;

class TrieNode {
private:
   TrieNode links[26];
   bool isEnd;
};

class Trie {
public:
};

int main(int argc, char** argv) {

  return 0;
}
