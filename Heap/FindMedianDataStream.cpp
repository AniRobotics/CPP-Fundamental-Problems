/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.


Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2


Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MedianFinder {
public:
  MedianFinder() {}
  std::vector<int> sortedData;
  void addNum(int num);
  double findMedian();
};

void MedianFinder::addNum(int num){
  sortedData.push_back(num);
  auto cmp = [](int a, int b){return a < b;};
  std::sort(sortedData.begin(), sortedData.end(), cmp);
}

double MedianFinder::findMedian(){
  if (sortedData.size()%2 == 0) {
    return ((double)sortedData[sortedData.size()/2]+(double)sortedData[sortedData.size()/2 - 1])/2;
  }
  return (double)sortedData[sortedData.size()/2];
}

int main (int argc, char** argv) {
  MedianFinder* obj = new MedianFinder();
  obj->addNum(2);
  obj->addNum(3);
  std::cout << "Median: " <<  obj->findMedian() << std::endl;

  obj->addNum(4);
  std::cout << "Median: " <<  obj->findMedian() << std::endl;

  // Free the allocated memory
  delete obj;

  return 0;
}
