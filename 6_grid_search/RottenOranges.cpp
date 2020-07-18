#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

void infect(int row_ind, int col_ind, std::vector<std::vector<int>> &orange_grid, std::set<std::string> &fresh_set, std::queue<std::vector<int>>& toExplore)
{
    // First check if you are in the grid
    if (row_ind<0 || row_ind>=orange_grid.size() || col_ind<0 || col_ind>=orange_grid[0].size())
    {
        return;
    }
    
    if (orange_grid[row_ind][col_ind]==1)
    {
        orange_grid[row_ind][col_ind] = 2;
        toExplore.push(std::vector<int> ({row_ind, col_ind}));        
        std::vector<int> data = toExplore.front();        
        fresh_set.erase(std::to_string(row_ind)+std::to_string(col_ind));
    }
}

int timeMakeRotten(std::vector<std::vector<int>>& orange_grid)
{
    // Set of row-column pairs of fresh oranges
    std::set<std::string> fresh_set;
    for (size_t i = 0; i < orange_grid.size(); i++)
    {
        for (size_t j = 0; j < orange_grid[0].size(); j++)
        {
            if (orange_grid[i][j] == 1)
            {
                fresh_set.insert(to_string(i)+to_string(j));
            }
        }
    }
    
    //    for (auto i=fresh_set.begin(); i!=fresh_set.end(); i++)
//    {
//        std::cout << *i << ",";
//    }
//    std::cout << std::endl;
    
    // Create a queue to be used for BFS traversal to infect fresh oranges
    std::queue<std::vector<int>> toExplore;
    toExplore.push(std::vector<int> ({0, 0})); // always contains a rotten orange

    int total_minutes = 0;
    while (!toExplore.empty())
    {
        int current_sz = toExplore.size();
        
        // pop all the current elements from toExplore
        for (size_t i = 0; i < current_sz; i++)
        {
            std::vector<int> current_ind_pair = toExplore.front();
            toExplore.pop();            

            if (orange_grid[current_ind_pair[0]][current_ind_pair[1]] == 2)
            {
                // infect upper cell
                infect(current_ind_pair[0]+1, current_ind_pair[1], orange_grid, fresh_set, toExplore);
                // infect lower cell
                infect(current_ind_pair[0]-1, current_ind_pair[1], orange_grid, fresh_set, toExplore);
                // infect right cell
                infect(current_ind_pair[0], current_ind_pair[1]+1, orange_grid, fresh_set, toExplore);
                // infect left cell
                infect(current_ind_pair[0], current_ind_pair[1]-1, orange_grid, fresh_set, toExplore);
            }
            // std::cout << "---------------" << std::endl;
        }
        
        // if toExplore is non-empty at this point, then we can not infect anymore
        // else increament the time
        if (!toExplore.empty())
        {
            total_minutes++;
        }
    }
    
    // if fresh_set is non-empty at this point, then indicate impossible case (-1) 
    if (!fresh_set.empty())
    {
        total_minutes = -1;
    }
    return total_minutes;
}

int main(int argc, char** argv) {
    
    // Orange grid
    std::vector<std::vector<int>> orange_grid = {{2,1,1},{1,1,0},{0,1,1}};
    int total_minutes = timeMakeRotten(orange_grid);
    
    std::cout << "Time to make all rotten: " << total_minutes << " minutes" << std::endl;
    return 0;
}

