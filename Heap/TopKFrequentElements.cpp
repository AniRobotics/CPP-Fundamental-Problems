/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
  std::vector<int> vec = {4,4,1,1,1,2,2,3};

  auto cmp = [](std::pair<int,int> p1, std::pair<int,int> p2) {return p1.second < p2.second;};
  std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, decltype(cmp)> pq(cmp);

  // Create a hash-map
  std::unordered_map<int,int> hmp;
  for (auto i : vec) {
    hmp[i]++;
  }

  // Put all the elements in the hash-map into the priority-queue
  for (auto i : hmp) {
    std::cout << i.first << "," << i.second << std::endl;
    pq.push(i);
  }

  std::cout << "Order of the numbers based on their frequencies" << std::endl;
  while (!pq.empty()) {
    std::cout << pq.top().first << std::endl;
    pq.pop();
  }

  return 0;
}
