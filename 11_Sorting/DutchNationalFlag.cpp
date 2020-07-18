#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
	std::vector<int> arr = {0,1,0,1,2,1,0,1,2,1,0};

	int zero_index =0, one_index = 0, two_index = arr.size()-1;
	while (one_index < two_index) {
		int current_element = arr[one_index];

		if (current_element == 0) {
			arr[one_index] = arr[zero_index];
			arr[zero_index] = current_element;
			zero_index++;
			one_index++;
		}
		else if (current_element == 2) {
			arr[one_index] = arr[two_index];
			arr[two_index] = current_element;
			two_index--;
		}
		else {
			one_index++;
		}
	}

	// Print the sorted array
	for(auto i = arr.begin(); i != arr.end(); i++) {
		std::cout << *i << ",";
	}
	std::cout << std::endl;

	return 0;
}
