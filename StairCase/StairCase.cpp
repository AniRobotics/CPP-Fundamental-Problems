#include <iostream>

using namespace std;

int FindNumWays(int num_stairs) {
  if (num_stairs == 2) {
    return 2;
  }

  if (num_stairs == 1) {
    return 1;
  }

  if (num_stairs == 0) {
    return 0;
  }

  return FindNumWays(num_stairs-1) + FindNumWays(num_stairs-2);
}

int main (int argc, char** argv) {
  int NumStairs = 6;
  int NumWays = FindNumWays(NumStairs);

  std::cout << NumWays << " ways to climb " << NumStairs << std::endl;

  return 0;
}
