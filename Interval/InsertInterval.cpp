/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char** argv) {
  // // Example 1
  // std::vector<std::vector<int>> intervals = {{1,3},{6,9}};
  // std::vector<int> newInterval = {2,5};

  // Example 2
  std::vector<std::vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
  std::vector<int> newInterval = {4,8};

  std::vector<std::vector<int>> resIntervals;
  auto cmp = [](std::vector<int> first, std::vector<int> second){return first[0] > second[0];};
  std::priority_queue<std::vector<int>,std::vector<std::vector<int>>,decltype(cmp)> pq(cmp);

  for (auto interval : intervals) {
    pq.push(interval);
  }

  while (!pq.empty()) {
    std::vector<int> interval = pq.top();
    pq.pop();
    if (newInterval[0] > interval[1]) {
      resIntervals.push_back(interval);
    }
    else if (newInterval[1] < interval[0]) {
      resIntervals.push_back(newInterval);
      resIntervals.push_back(interval);
    }
    else if (newInterval[0] == interval[0] && newInterval[1] == interval[1]) {
      continue;
    }
    else {
      newInterval[0] = min(interval[0], newInterval[0]);
      newInterval[1] = max(interval[1], newInterval[1]);
      pq.push(newInterval);
    }
  }

  std::cout << "Size of queue: " << pq.size() << std::endl;

  // Print the new intervals
  std::cout << "New set of intervals" << std::endl;
  for (auto interval : resIntervals) {
    std::cout << "[";
    for (auto entry : interval) {
      std::cout << entry << ",";
    }
    std::cout << "]" << std::endl;
  }

  return 0;
}
