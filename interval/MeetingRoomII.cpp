/*
Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] where si < ei, find the minimum number of conference room
required.

Example 1
Input : [[0,30],[5,10],[15,20]]
Output : 2

Example 2
Input : [[7,10],[2,4]]
Output : 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, char** argv) {
  // Example 1
  std::vector<std::vector<int>> intv = {{0,30},{5,10},{15,20}};

  // // Example 2
  // std::vector<std::vector<int>> intv = {{7,10},{2,4}};

  // Sort the meetings based on the earliest starting time
  auto cmp = [](std::vector<int> v1, std::vector<int> v2) {return v1[0] < v2[0];};
  sort(intv.begin(), intv.end(), cmp);

  // Sorted Intervals
  std::cout << "Intervals based on earliest start" << std::endl;
  for (auto vec : intv) {
    std::cout << "[" << vec[0] << "," << vec[1] << "]" << std::endl;
  }

  // Determine minimum number of meeting rooms
  int numRooms = 0;
  // cmp2 does similar job as cmp. However, to use it with priority queue
  // we have to use the comparison sign flipped here.
  auto cmp2 = [](std::vector<int> v1, std::vector<int> v2){return v1[1] > v2[1];};
  std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp2)> pq(cmp2);
  pq.push(intv[0]);

  // pq.push(intv[1]); pq.push(intv[2]);
  // while (!pq.empty()) {
  //   std::vector<int> it = pq.top();
  //   pq.pop();
  //   std::cout << "[" << it[0] << "," << it[1] << std::endl;
  // }

  for (size_t i = 1; i < intv.size(); i++) {
    std::vector<int> current = intv[i];

    std::vector<int> previous = pq.top();
    pq.pop();

    if (current[0] > previous[1]) {
      previous[1] = current[1];
    }
    else {
      pq.push(current);
    }
    pq.push(previous);
  }

  std::cout << "Minimum no. of rooms: " << pq.size() << std::endl;

  return 0;
}
