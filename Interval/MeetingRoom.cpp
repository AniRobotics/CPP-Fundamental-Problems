/*
Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] where si < ei, determine if a person could attain all the meetings

Example 1
Input : [[0,30],[5,10],[15,20]]
Output : false

Example 2
Input : [[7,10],[2,4]]
Output : true
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
  // Example 1
  std::vector<std::vector<int>> intv = {{0,30},{5,10},{15,20}};

  // // Example 2
  // std::vector<std::vector<int>> intv = {{7,10},{2,4}};

  bool couldAttain = true;

  // Sort the meetings based on the earliest starting time
  auto cmp = [](std::vector<int> v1, std::vector<int> v2) {return v1[0] < v2[0];};
  sort(intv.begin(), intv.end(), cmp);

  // Sorted Intervals
  for (auto vec : intv) {
    std::cout << "[" << vec[0] << "," << vec[1] << "]" << std::endl;
  }

  // Check for any overlaps
  std::vector<int> previous = intv[0];
  for (int i = 1; i < (int)intv.size(); i++) {
    if (previous[1] > intv[i][0]) {
      couldAttain = false;
      break;
    }
    else {
      previous[1] = intv[i][1];
    }
  }

  if (couldAttain) {
    std::cout << "All meetings can be attended" << std::endl;
  }
  else {
    std::cout << "All meetings can not be attended" << std::endl;
  }

  return 0;
}
