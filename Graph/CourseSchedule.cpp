/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main (int argc, char** argv) {
  int numCourses = 4;
  std::vector<std::vector<int>> prerequisites = {{3,2},{3,1},{1,0}};

  // convert the prerequisites 2d array into a graph. However for this problem,
  // it is enough to track the number of inward pointing arrows to any vertex.
  std::vector<int> inDegrees(numCourses, 0);
  for (size_t i = 0; i < prerequisites.size(); i++) {
    inDegrees[prerequisites[i][0]]++;
  }

  // We need to perform topological sort
  std::stack<int> stk;
  for (size_t i = 0; i < inDegrees.size(); i++) {
    if (inDegrees[i] == 0) {
      stk.push(prerequisites[i][1]);
    }
  }

  int count = 0;
  while(!stk.empty()) {
    int current = stk.top();
    std::cout << current << std::endl;
    stk.pop();
    count++;

    for (size_t i = 0; i < prerequisites.size(); i++) {
      if (prerequisites[i][1] = current) {
        inDegrees[prerequisites[i][0]]--;
        if (inDegrees[prerequisites[i][0]] == 0) {
          stk.push(prerequisites[i][0]);
        }
      }
    }
  }

  if (count == numCourses) {
    std::cout << "All courses can be finished" << std::endl;
  }

  return 0;
}
