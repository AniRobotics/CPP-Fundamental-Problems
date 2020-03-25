#include <iostream>
#include <vector>

using namespace std;

void sink(vector<vector<int>>& grid, int ri, int cj)
{
    if (ri<0 || ri>grid.size()-1 || cj<0 || cj>grid[0].size()-1 || grid[ri][cj] == 0)
    {
        return;
    }
    
    grid[ri][cj] = 0;
    
    sink(grid, ri-1, cj);
    sink(grid, ri+1, cj);
    sink(grid, ri, cj-1);
    sink(grid, ri, cj+1);
    
    return;
    
}

int numIslands(vector<vector<int>>& grid)
{
    int num_islands = 0;
    for (size_t i=0; i<grid.size(); i++)
    {
        for (size_t j=0; j<grid[0].size(); j++) 
        {   
            // std::cout << grid[i][j] << std::endl;
            if (grid[i][j] == 1)
            {
                sink(grid, i, j);
                num_islands++;
            }
        }
    }
    return num_islands;
}

int main(int argc, char** argv) {
    
    // Example 1
    std::vector<vector<int>> grid = {{1,1,1,1,0}, {1,1,1,1,0}, {1,1,0,0,0}, {0,0,0,0,0}};
    
    // Call numIsLands method
    int num_island = numIslands(grid);
    std::cout << "Number of islands: " << num_island << std::endl;
    
    // Example 2
    std::vector<vector<int>> grid2 = {{1,1,0,0,0}, {1,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,1}};
    
    // Call numIsLands method
    int num_island2 = numIslands(grid2);
    std::cout << "Number of islands: " << num_island2 << std::endl;
    
    return 0;
}

