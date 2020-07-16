#include "tree_builder.h"

void all_paths_DFS(std::shared_ptr<Node> node, std::string path, std::vector<string>& all_paths) {
  if (node != nullptr) {
    path += std::to_string(node->get_value());

    if (node->get_left() == nullptr && node->get_right() ==  nullptr) {
      // std::cout << "new path added" << std::endl;
      all_paths.push_back(path);
    }

    all_paths_DFS(node->get_left(), path+"->", all_paths);
    all_paths_DFS(node->get_right(), path+"->", all_paths);
  }
}

int main (int argc, char** argv) {
  // Build the tree
  std::vector<int> node_val = {60, 50, 70, 40, 55, 65, 80};
  std::shared_ptr<Node> root =build_btree(node_val);

  // Find all paths of binary tree
  std::vector<string> all_paths;
  std::string path = "";
  all_paths_DFS(root, path, all_paths);
  std::cout << "all paths computed" << std::endl;

  // Print all the paths
  for (auto p = all_paths.begin(); p != all_paths.end(); p++) {
    std::cout << *p << std::endl;
  }

  return 0;
}
