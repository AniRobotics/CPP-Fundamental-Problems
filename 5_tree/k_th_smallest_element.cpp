#include "tree_builder.h"

/*
                60
              /   \
            50     70      <----- Tree used for this problem
          /   \  /   \
        40    55 65   80
Find lowest common ancestor for the nodes 70 and 80
*/

void find_kth_smallest_inorderDFS(std::shared_ptr<Node> node, int small_data[], int k) {
  if (node != nullptr) {
    find_kth_smallest_inorderDFS(node->get_left(), small_data, k);

    small_data[0]++;
    if (small_data[0] == k) {
      small_data[1] = node->get_value();
      return;
    }

    find_kth_smallest_inorderDFS(node->get_right(), small_data, k);
  }
}

int main (int argc, char** argv) {
  // Build the tree
  std::vector<int> node_val = {60, 50, 70, 40, 55, 65, 80};
  std::shared_ptr<Node> root =build_btree(node_val);

  // Find kth smallest element of a BST
  int k = 3;
  int small_data[2];
  find_kth_smallest_inorderDFS(root, small_data, k);
  std::cout << "Kth smallest element is: " << small_data[1] << std::endl;

  return 0;
}
