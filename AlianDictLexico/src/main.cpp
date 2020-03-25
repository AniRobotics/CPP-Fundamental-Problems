#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check_word_lexico(std::string word_arr[], int num_words, std::string order){
	// Step-1: Map the order to an array
	int mapped_order[26];
	for (size_t i = 0; i < order.size(); i++){
		mapped_order[order[i] - 'a'] = i;
	}

//	for (int i = 0; i < 26; i++){
//		std::cout << mapped_order[i] << "," << std::endl;
//	}

	// Now we will compare each word in word_arr with each other
	for (int i = 0; i < num_words; i++) {
		for (int j = i+1; j < num_words; j++) {
			int min_num_compare = min(word_arr[i].size(), word_arr[j].size());
			// Now we will compare character by character
			for (int k = 0; k < min_num_compare; k++) {
				char iWordChar = word_arr[i][k];
				char jWordChar = word_arr[j][k];
				if (mapped_order[iWordChar - 'a'] < mapped_order[jWordChar - 'a']) {
					break;
				}
				else if (mapped_order[iWordChar - 'a'] > mapped_order[jWordChar - 'a']) {
					return false;
				}
				else {
					if (k == min_num_compare - 1 && word_arr[i].size() > word_arr[j].size()) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main(int argc, char** argv) {
	int num_words = 2;
	std::string word_arr[2] = {"hello", "leetcode"};
	std:string order = "hlabcdefgijkmnopqrstuvwxyz";

	bool answer = check_word_lexico(word_arr, num_words, order);
	std::cout << "All the words are in lexicographical order: " << answer << std::endl;

	return 0;
}
