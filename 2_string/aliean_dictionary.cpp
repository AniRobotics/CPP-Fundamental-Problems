#include <iostream>
#include <vector>

using namespace std;

bool aliean_dictionary(std::vector<std::string>& words, std::string order) {
  int ord_arr[26];
  for (int i = 0; i < sizeof(ord_arr)/sizeof(ord_arr[0]); i++) {
    ord_arr[order[i]-'a'] = i;
  }

  // for (int i = 0; i < sizeof(ord_arr)/sizeof(ord_arr[0]); i++) {
  //   std::cout << ord_arr[i] << std::endl;
  // }

  return true;
}

int main(int argc, char** argv) {
  std::vector<std::string> words = {"hello", "leetcode"};
  std::string order = "hlabcdefgijkmnopqrstuvwxyz";
  bool valid = aliean_dictionary(words, order);
  return 0;
}
