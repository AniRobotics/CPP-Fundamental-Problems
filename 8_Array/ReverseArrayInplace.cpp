#include <iostream>

using namespace std;

int main(int argc, char** argv){

	int start_ind = 1, end_ind = 3;
	int arr[] = {1,2,3,4,5,6};

	int temp;
	while (start_ind < end_ind) {
		temp = arr[start_ind];
		arr[start_ind] = arr[end_ind];
		arr[end_ind] = temp;

		start_ind++;
		end_ind--;
	}

	// Print the reversed array
	for(int i = 0; i < 6; i++) {
		std::cout << arr[i] << ",";
	}
	std::cout << std::endl;

	return 0;
}
