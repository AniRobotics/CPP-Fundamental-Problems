#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>

using namespace std;

/* Binary search using while loop */
int binary_search(int arr[], int &target, int &sz){
  int start_ind = 0;
  int end_ind = sz-1;
  int mid;
  while (start_ind <= end_ind){
    mid = (start_ind + end_ind)/2;
    if (arr[mid] == target) {
      return mid;
    }
    else if (arr[mid] > target) {
      end_ind = mid;
    }
    else {
      start_ind = mid + 1;
    }
  }
  return -1; // target does not exist.
}

/* Binary search using recursion */
int search_recur(int arr[], int &target, int start_ind, int end_ind){
  if (start_ind > end_ind) {
    return -1;
  }
  int mid = (start_ind + end_ind)/2;
  if (arr[mid] == target) {
    return mid;
  }
  else if (arr[mid] > target) {
    return search_recur(arr, target, start_ind, mid);
  }
  else {
    return search_recur(arr, target, mid + 1, end_ind);
  }
}

int binary_search_recursion(int arr[], int &target, int &sz){
  return search_recur(arr, target, 0, sz-1);
}

int main(int argc, char** argv){
  int arr[] = {10, 20, 30, 50, 60, 70, 80, 90, 100};
  int target = 50;
  int n = sizeof(arr)/sizeof(arr[0]);

  int target_ind = binary_search(arr, target, n);
  std::cout << "Index of the target=" << target_ind << std::endl;

  int target_ind_recur = binary_search_recursion(arr, target, n);
  std::cout << "Index of the target=" << target_ind_recur << std::endl;
}
