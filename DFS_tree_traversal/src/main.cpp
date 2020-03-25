#include <iostream>
#include <vector>
#include <queue>
#include <memory>

using namespace std;

// Node: the building block of tree
struct Node
{
	Node(int* value) : value(value) {};
	int* value;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
};

// Build the tree
std::shared_ptr<Node> build_btree(vector<int>& values)
{
	size_t index = 0;

	// Create the root binary tree
	std::shared_ptr<Node> root;
	root = std::make_shared<Node> (Node(&values[index++]));
	std::cout << "Binary-tree root created ..." << std::endl;

	// Traverse the Binary tree as per BFS and insert the nodes
	std::queue<std::shared_ptr<Node>> q;
	q.push(root);

	std::shared_ptr<Node> current;
	while (!q.empty() && index<values.size())
	{
		// Get the current node to be explored
		current = q.front();
		q.pop();

		// insert new left node if it is currently nullptr
		if (current->left == nullptr)
		{
			current->left = std::make_shared<Node> (Node(&values[index++]));
			q.push(current->left);
		}

		// insert new right node if it is currently nullptr
		if (current->right == nullptr)
		{
			current->right = std::make_shared<Node> (Node(&values[index++]));
			q.push(current->right);
		}
	}
	std::cout << "Tree built ..." << std::endl;

	return root;
}

// Pre-Order-DFS
void traverseDFS(std::shared_ptr<Node>& node)
{
	if (node != nullptr)
	{
		std::cout << *(node->value) << std::endl;

		traverseDFS(node->left);
		traverseDFS(node->right);
	}
}

int main(int argc, char** argv)
{
	// Values to be inserted to the tree
	std::vector<int> values = {5, 2, 6, 8, 9, 10, 11};

	// Call build tree method
	std::shared_ptr<Node> tree_root = build_btree(values);

	// Print the tree elements using BFS tree traversal
	traverseDFS(tree_root);

	return 0;
}
