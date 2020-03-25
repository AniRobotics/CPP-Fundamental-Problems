#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void targetSumPair(int arr_ele[], int arr_sz, int target, vector<int>& valid_pair)
{
	// seen elements
	std::set<int> seen_elements;
	for (int i=0; i<arr_sz; i++)
	{
		seen_elements.insert(arr_ele[i]);
	}

	// print seen_elements
	for (std::set<int>::iterator i=seen_elements.begin(); i!=seen_elements.end(); i++)
	{
		std::cout << *i << ", ";
	}
	std::cout << std::endl;

	// print using for_each
	std::for_each(seen_elements.begin(), seen_elements.end(), [](const int &i){ cout << i << ", ";});
	std::cout << std::endl;

	// search for pair
	for (int i=0; i<arr_sz; i++)
	{
		std::cout << "current element: " << arr_ele[i] << std::endl;
		if (seen_elements.find(target-arr_ele[i]) != seen_elements.end())
		{
			valid_pair.push_back(arr_ele[i]);
			valid_pair.push_back(target-arr_ele[i]);

			break;
		}
	}
}

int main(int argc, char** argv)
{
	int num_ele = 4;
	int target = 8;
	int arr_ele[num_ele] = {1, 5, 9, 7};

	// create a vector to hold the pair
	std::vector<int> valid_pair;

	// Call targetSumPair
	targetSumPair(arr_ele, num_ele, target, valid_pair);

	// Check if such pair exists
	if (valid_pair.size()==2)
	{
		std::cout << "[" << valid_pair[0] << ", " << valid_pair[1] << "]" << std::endl;
	}
	return 0;
}
