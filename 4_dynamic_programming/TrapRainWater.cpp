#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	// Given bar heights at location index
	std::vector<int> bar_heights = {0,1,0,2,1,0,1,3,2,1,2,1};

	// Create two dp arrays to keep track of left and right maximum wall heights
	int left_max[bar_heights.size()], right_max[bar_heights.size()];
	left_max[0] = bar_heights[0];
	right_max[bar_heights.size()-1] = 0;

	// Fill-in the left_max array
	for(int i = 1; i < bar_heights.size(); i++) {
		left_max[i] = max(left_max[i-1], bar_heights[i]);
	}

	// Fill-in the right_max array
	for(int i = bar_heights.size()-2; i>=0; i--) {
		right_max[i] = max(right_max[i+1], bar_heights[i]);
	}

	// Now count water at each index
	int water_count = 0, total_water = 0;
	for(size_t i = 0; i < bar_heights.size(); i++) {
		water_count = min(left_max[i],right_max[i])-bar_heights[i];
		if (water_count > 0) {
			total_water += water_count;
		}
	}

	std::cout << "Total water can be trapped: " << total_water << std::endl;
	return 0;
}
