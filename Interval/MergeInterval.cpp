/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main (int argc, char** argv) {
  std::vector<std::vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
  std::vector<std::vector<int>> resInterval;

  auto cmp = [](std::vector<int> first, std::vector<int> second){return first[0] > second[0];};
  std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,decltype(cmp)> pq(cmp);

  for (auto interval : intervals) {
    pq.push(interval);
  }

  auto currInter = pq.top();
  bool insertFlag = false;
  // pq.pop();

  while (!pq.empty()) {
    auto interval = pq.top();
    pq.pop();

    if (currInter[0] > interval[1]) {
      resInterval.push_back(interval);
    }
    else if (currInter[1] < interval[0]) {
      if (!insertFlag) {
        resInterval.push_back(currInter);
        insertFlag = true;
      }
      resInterval.push_back(interval);
    }
    else if (currInter[0] == interval[0] && currInter[1] == interval[1]) {
      continue;
    }
    else {
      currInter[0] = min(currInter[0],interval[0]);
      currInter[1] = max(currInter[1],interval[1]);
      pq.push(currInter);
      insertFlag = false;

    }
  }

  // Print the new intervals
  std::cout << "New set of intervals" << std::endl;
  for (auto interval : resInterval) {
    std::cout << "[";
    for (auto entry : interval) {
      std::cout << entry << ",";
    }
    std::cout << "]" << std::endl;
  }

  return 0;
}
