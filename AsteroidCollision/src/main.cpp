#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

std::vector<int> AsteroidColli(int asteroids[], int num_elements) {
	std::vector<int> remaining;

	std::stack<int> asteroid_order;
	int i = 0;

	while (i < num_elements) {
		if (asteroids[i] > 0) {
			asteroid_order.push(asteroids[i]);
		}
		else{
			while (!asteroid_order.empty() && asteroid_order.top()>0 && asteroid_order.top() < abs(asteroids[i])) {
				asteroid_order.pop();
			}
			if (asteroid_order.empty() || asteroid_order.top() < 0) {
				asteroid_order.push(asteroids[i]);
			}
			else if (!asteroid_order.empty() && asteroid_order.top()>0 && asteroid_order.top() == abs(asteroids[i])){
				asteroid_order.pop();
			}
		}
		i++;
	}

	// Store whatever remained into the remaining vector
	while (!asteroid_order.empty()) {
		remaining.push_back(asteroid_order.top());
		asteroid_order.pop();
	}
	return remaining;
}

int main(int argc, char** argv) {
//	/* Example 1 */
//	int num_elements = 3;
//	int asteroids[] = {5,10,-5};

//	/* Example 2 */
//	int num_elements = 2;
//	int asteroids[] = {8,-8};

//	/* Example 3 */
//	int num_elements = 3;
//	int asteroids[] = {10, 2, -5};

	/* Example 4 */
	int num_elements = 4;
	int asteroids[] = {-2,-1,1,2};

	std::vector<int> output = AsteroidColli(asteroids, num_elements);
	std::cout << "[";
	for (auto i = output.begin(); i != output.end(); i++)
		std::cout << *i << ",";
	std::cout << "]" << std::endl;

	return 0;
}
