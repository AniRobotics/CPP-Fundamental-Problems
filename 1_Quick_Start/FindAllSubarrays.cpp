#include <iostream>
#include <vector>

using namespace std;

void FindAllSubArrays(int idx, std::vector<int>& arr, std::vector<std::vector<int>>& AllSubarrays) {
  if (idx >= arr.size()) {
    std::vector<int> temp;
    AllSubarrays.push_back(temp);
    return;
  }

  FindAllSubArrays(idx+1,arr,AllSubarrays);

  size_t size_so_far = AllSubarrays.size();
  for (size_t i = 0; i < size_so_far; i++) {
    std::vector<int> new_temp(AllSubarrays[i]);
    new_temp.push_back(arr[idx]);
    AllSubarrays.push_back(new_temp);
  }
}

void PrintAllSubArrays(std::vector<std::vector<int>>& AllSubarrays) {
  for (size_t i = 0; i < AllSubarrays.size(); i++) {
    for (size_t j = 0; j < AllSubarrays[i].size(); j++) {
      std::cout << AllSubarrays[i][j] << ",";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char** argv) {
  std::vector<int> arr = {1,7,5,9};
  std::vector<std::vector<int>> AllSubarrays;

  FindAllSubArrays(0,arr,AllSubarrays);

  PrintAllSubArrays(AllSubarrays);

  return 0;
}
