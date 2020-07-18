#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string const data_str, int start_ind, int end_ind){
    if (start_ind == end_ind) {
        return true;
    }
    
    start_ind++;
    end_ind--;
    
    return (data_str[start_ind] == data_str[end_ind]) && is_palindrome(data_str, start_ind, end_ind);
}

int main(int argc, char** argv) {
    string data_str = "abcdcba";
    
    for (size_t i = 0; i < data_str.size(); i++){
        cout << data_str[i] << ", ";
    }
    cout << endl;
    
    string sub_data_str = "";
    
    for (size_t i = 2; i < data_str.size()-2; i++){
        sub_data_str += data_str[i];
    }
    cout << sub_data_str << endl;
    
    // call is_palindrome
    bool answer = is_palindrome(data_str, 0, data_str.size()-1);
    cout << data_str << " is a palindrome: " << answer;
    
    return 0;
}
