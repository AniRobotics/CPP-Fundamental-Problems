#include <iostream>
#include <vector>
using namespace std;

int paintHouse(vector<vector<int>>& cm)
{
    for (size_t i=1; i<cm[0].size(); i++)
    {
        cm[i][0] += min(cm[i-1][1], cm[i-1][2]);
        cm[i][1] += min(cm[i-1][0], cm[i-1][2]);
        cm[i][2] += min(cm[i-1][0], cm[i-1][1]);
    }
    
    return min(min(cm[cm.size()-1][0], cm[cm.size()-1][1]), cm[cm.size()-1][2]);
}

int main(int argc, char** argv) {
    
    // Given paint cost matrix
    vector<vector<int>> cost_mat = {{17, 2, 17}, {16, 16, 5}, {14, 3, 19}};
    
    int min_cost = paintHouse(cost_mat);
    std::cout << "Minimum cost: " << min_cost << std::endl;
    
    return 0;
}
