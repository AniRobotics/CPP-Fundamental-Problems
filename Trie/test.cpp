#include <iostream>
#include <memory>

class TrieNode {
public:
  std::shared_ptr<TrieNode> links{new TrieNode[26],
     std::default_delete<TrieNode[]>()};
  bool isEnd;
  TrieNode () {}
};

int main (int argc, char** argv) {
  std::shared_ptr<int> sp( new int[10], std::default_delete<int[]>() );

  return 0;
}
