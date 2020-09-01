/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
*/

#include <iostream>
using namespace std;

int main (int argc, char** argv) {
  int a = 2;
  int b = 3;

  int opXOR, carryAND; 

  while (b) {
    opXOR = (a^b);
    carryAND = (a&b) << 1;
    a = opXOR;
    b = carryAND;
  }  
  std::cout << "Sum is: " << opXOR << std::endl;
  return 0;
}
