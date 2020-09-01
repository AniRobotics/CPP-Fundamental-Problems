/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.


Note:

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
*/

/*
Idea:
Step-1: Sort the intervals array based on the earliest start time.
Step-2: Check for overlap (i.e., end time of the previous interval, start time of the current interval)
Step-3: If there is an overlap, increase the minRmv counter by 1.
Step-4: Update the end time of the previous with the minimum between the end times of the old previous and current.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

using namespace std;

int main (int argc, char** argv) {
  // Example 1
  // std::vector<std::vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};

  // Example 2
  // std::vector<std::vector<int>> intervals = {{1,2},{1,2},{1,2}};

  // Example 3
  std::vector<std::vector<int>> intervals = {{1,2},{2,3}};

  // Sort the intervals, based on start times (ascending order)
  sort(intervals.begin(), intervals.end(), [](std::vector<int> v1, std::vector<int> v2){
              return v1[0] < v2[0];});

  // Print the sorted intervals
  for (auto intv : intervals) {
    std::cout << "[" << intv[0] << "," << intv[1] << "], ";
  }
  std::cout << std::endl;

  int minRmv = 0;
  std::vector<int> previous = intervals[0];

  for (int i = 1; i < (int)intervals.size(); i++) {
    if (previous[1] > intervals[i][0]) {
      previous[1] = min(previous[1],intervals[i][1]);
      minRmv++;
    }
  }

  std::cout << "Min remove: " << minRmv << std::endl;

  return 0;
}
