#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	std::cout << "Print matrix in spiral order" << std::endl;
	// The given matrix
	std::vector<std::vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};

	// Start of spiral matrix reading
	int ul = 0, bl = arr.size()-1;
	int ll = 0, rl = arr[0].size()-1;

	size_t total_ele = arr.size() * arr[0].size();
	std::vector<int> spiral_data;

	std::cout << total_ele << std::endl;
	std::cout << spiral_data.size() << endl;

	while (total_ele>spiral_data.size())
	{
		// step-1: traverse from left to right
		for (int i = ll; i <= rl; i++) {
			spiral_data.push_back(arr[ll][i]);
		}
		ul++; // shrink upper limit

		// step-2: traverse top to bottom along last column
		for (int i = ul; i <= bl; i++) {
			spiral_data.push_back(arr[i][rl]);
		}
		rl--; // shrink lower limit

		// step-3: traverse right to left along the last row
		for (int i = rl; i >= ll; i--) {
			spiral_data.push_back(arr[bl][i]);
		}
		bl--;

		// step-4: traverse bottom to top along teh first column
		for (int i = bl; i >= ul; i--) {
			spiral_data.push_back(arr[i][ll]);
		}
		ll++;
	}

	// print the elements of the spiral_data
	std::cout << "[";
	for (auto j = spiral_data.begin(); j != spiral_data.end(); j++) {
		std::cout << *j << ",";
	}
	std::cout << "]" << std::endl;

	return 0;
}
