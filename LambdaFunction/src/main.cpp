#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Rule for sorting two numbers
bool sort_method(int a, int b){
	return a < b;
}

auto cmp = [](int a, int b){ return a < b; };

int main(int argc, char** argv) {
	std::vector<int> vec = {1, 2, 3, 6, 9, 7};
	std::vector<int> sorted_vec(vec.size());

	// Print element of the vector object using iterator
	std::cout << "Given unsorted array: ";
	for(auto i = vec.begin(); i < vec.end(); i++) {
		std::cout << *i << ", ";
	}
	std::cout << std::endl;

	// Sort the elements of the vector objects
	std::sort(vec.begin(), vec.end(), sort_method);

	// Print the elements of the vector object after sorting
	std::cout << "In-place sorted array: ";
	for(auto i = vec.begin(); i < vec.end(); i++) {
		std::cout << *i << ", ";
	}
	std::cout << std::endl;

	// Now we will create another vector object
	std::cout << "------------------------" << std::endl;
	std::cout << "New given unsorted array: ";
	std::vector<int> new_vec = {10, 50, 8, 60, 40, 6, 4};
	for (auto i = new_vec.begin(); i < new_vec.end(); i++) {
		std::cout << *i << ", ";
	}
	std::cout << std::endl;

	// Now we will create a priority queue
	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

	for (auto i = new_vec.begin(); i < new_vec.end(); i++) {
		pq.push(*i);
	}

	// Now print the elements of the priority queue
	std::cout << "Elements of the priority queue: ";
	int temp;
	while (!pq.empty()) {
		temp = pq.top();
		std::cout << temp << ", ";
		pq.pop();
	}
	std::cout << std::endl;

	return 0;
}
