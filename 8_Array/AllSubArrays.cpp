#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void findAllSubArrays(std::vector<int>& ip_array, int index, std::vector<std::shared_ptr<std::vector<int>>>& all_subarrays)
{
    if (index >= ip_array.size()) 
    {
         all_subarrays.push_back(std::make_shared<vector<int>> (vector<int> ({})));
        return; 
    }    
    
    findAllSubArrays(ip_array, index+1, all_subarrays);
            
    int n = all_subarrays.size();    
    
    for (size_t i=0; i<n; i++)
    {
        std::shared_ptr<std::vector<int>> temp =  std::make_shared<std::vector<int>> (vector<int> (*all_subarrays[i]));
        temp->push_back(ip_array[index]);
        all_subarrays.push_back(temp);
    }
}

int main(int argc, char** argv) {
    
    std::vector<int> ip_array = {1, 7, 5, 9};
    
    std::vector<std::shared_ptr<std::vector<int>>> all_subarrays; 
    findAllSubArrays(ip_array, 0, all_subarrays);
    
    // Print all the sub-arrays
    for (size_t i=0; i<all_subarrays.size(); i++)
    {
        std::cout << "[";
        for (size_t j=0; j<all_subarrays[i]->size(); j++)
        {
            std::cout << all_subarrays[i]->at(j) << ",";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
