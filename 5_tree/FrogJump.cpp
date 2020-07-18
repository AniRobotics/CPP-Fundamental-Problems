#include <iostream>
#include <utility>
#include <queue>
#include <set>

using namespace std;

bool jumpStones(std::vector<int> &stones)
{
    // Create a set with the locations of the stones
    std::set<int> stone_loc;
    for (size_t i = 0; i < stones.size(); i++)
    {
        stone_loc.insert(stones[i]);
    }
    pair<int,int> start(0,0); // pair(stone_index,jump_length)
    
    std::queue<pair<int,int>> toExplore;
    toExplore.push(start);

    pair<int,int> current;
    int new_loc;
    while (!toExplore.empty())
    {
        current = toExplore.front();
        toExplore.pop();
        
        for (int jump=current.second-1; jump<=current.second+1; jump++)
        {
            if (jump <= 0) // since only forward movement is allowed
            {
                continue;
            }            
            
            new_loc = current.first + jump; // new location
            
            if (stone_loc.find(new_loc) != stone_loc.end())
            {
                std::cout<< "From:" << "(loc,jump):(" << current.first << "," << current.second << ")" << std::endl;
                std::cout<< "To:" << "(loc,jump):(" << new_loc << "," << jump << ")" << std::endl;
                std::cout << "------------------" << std::endl;
                toExplore.push(pair<int,int> (new_loc,jump));
            }
            
            if (new_loc == stones[stones.size()-1]) 
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv) {
    // Given stone locations
    std::vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    
    bool checkCross = jumpStones(stones);
    std::cout << "Frog will cross the river: ";
    if (checkCross)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    return 0;
}
