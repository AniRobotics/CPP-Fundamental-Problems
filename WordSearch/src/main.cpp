#include <iostream>
#include <vector>

using namespace std;

#define R 3
#define C 4

bool searchDFS(char grid[R][C], std::size_t word_index, int row_ind, int col_ind, std::string word) {
	// Base case 1
	if (word_index == word.size()-1) {
		if (grid[row_ind][col_ind] == word[word_index]) {
			std::cout << "Index: " << word_index << std::endl;
			std::cout << "Found: " << word[word_index] << std::endl;
			return true;
		}
		else {
			return false;
		}
	}

	// Base case 2
	if (row_ind<0 || row_ind>R || col_ind<0 || col_ind>C || grid[row_ind][col_ind] != word[word_index]) {
		return false;
	}

	char temp = grid[row_ind][col_ind];
	grid[row_ind][col_ind] = ' ';
	if (searchDFS(grid, word_index+1, row_ind-1, col_ind, word) ||
		searchDFS(grid, word_index+1, row_ind+1, col_ind, word) ||
		searchDFS(grid, word_index+1, row_ind, col_ind-1, word) ||
		searchDFS(grid, word_index+1, row_ind, col_ind+1, word)) {
		return true;
	}
	grid[row_ind][col_ind] = temp;

	return false;
}

bool wordSearch() {
	// Given grid of characters
	char grid[R][C] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

	// Word to search for
	char word[] = "ABCCEE";

	// Find if the word we are searching for now, exists
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++) {
			if (grid[i][j] == word[0] && searchDFS(grid, std::size_t(0), i, j, word)) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char** argv){
	bool found = wordSearch();
	std::cout << "Found: " << found << std::endl;

	return 0;
}
