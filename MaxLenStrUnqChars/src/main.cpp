#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int lenCurrentUnq(std::string s) {
	std::set<char> uniq;

	for (size_t i = 0; i < s.size(); i++) {
		if (uniq.find(s[i]) != uniq.end()) {
			return -1;
		}
		else{
			uniq.insert(s[i]);
		}
	}
	return uniq.size();
}

void maxLenUnqStr(std::vector<std::string> &arr, std::size_t index, std::string current, int &max_len){
	std::cout << "current: " << current << std::endl;
	int current_len = lenCurrentUnq(current);
	std::cout << "current_len: " << current_len << std::endl;
	if (index == arr.size() && current_len > max_len) {
		std::cout << "Max length: " << max_len << std::endl;
		max_len = current_len;
		return;
	}

	if (index == arr.size()) {
		return;
	}

	maxLenUnqStr(arr, index+1, current, max_len);
	std::cout << arr[index] << std::endl;
	maxLenUnqStr(arr, index+1, current+arr[index], max_len);
}

int main(int argc, char** argv) {
	//Given array of strings
	std::vector<std::string> arr = {"un", "iq", "ue"};

	// Find maximum length of the string with unique chars
	// We will solve the problem recursively
	int max_len = 0;
	std::cout << "Calling maxLenUnqStr" << std::endl;
	maxLenUnqStr(arr, std::size_t(0), "", max_len);

	std::cout << "Maximum length: " << max_len << std::endl;

	return 0;
}
