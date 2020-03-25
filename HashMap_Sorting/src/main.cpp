#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// Create a lambda function to be used as priority queue
auto cmp = [](pair<string,int> left, pair<string,int> right) {return left.second > right.second;};

int main(int argc, char* argv[]){
	// Initialize an unordered map
	unordered_map<string,int> test_map;

	// Instantiate a priority queue
	priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> test_pqueue(cmp);

	// Insert values to the unordered map
	test_map.insert({"second",25});
	test_map.insert({"third",35});
	test_map.insert({"fourth",45});

	// Print the elements of test_map
	cout << "Printing the unordered_map: " << endl;
	for (auto& x : test_map){
		test_pqueue.push(x);
		cout << "key: " << x.first << ", " << "value: " << x.second << endl;
	}

	//Print values of the
	cout << "\nPrinting the priority_queue: " << endl;
	while (!test_pqueue.empty()){
		auto top_data =  test_pqueue.top();
		test_pqueue.pop();
		cout << "key: " << top_data.first << ", " << "value: " << top_data.second << endl;
	}

	return 0;
}
