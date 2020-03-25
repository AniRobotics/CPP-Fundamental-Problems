#include <iostream>
#include <memory>

using namespace std;

void fill_data_array(unique_ptr<int[]>& data_array, const int capacity, int start_index){
    for (size_t i = start_index; i < capacity; i++) {
        data_array[i] = 2*i;
    }
}

// Binary search using while loop
int binary_search(unique_ptr<int[]> &data_array, int target, int start_ind, int end_ind){
    int mid;
    
    if (target < data_array[start_ind] | target > data_array[end_ind]) {
        return -1;
    }
    
    while (start_ind <= end_ind){
        mid = (start_ind + end_ind)/2;
        
        if (data_array[mid] == target){
            return mid;
        }
        else if (data_array[mid] > target) {
            end_ind = mid;
        }
        else {
            start_ind = mid + 1;
        }
    }
    return -1;
}

// Binary search using recursion
int binary_search_recursion(unique_ptr<int[]> &data_array, int target, int start_ind, int end_ind){
    if (start_ind > end_ind) {
        return -1;
    }
    
    int mid_ind = (start_ind + end_ind)/2;
    
    if (data_array[mid_ind] == target) {
        return mid_ind;
    }
    else if (data_array[mid_ind] > target) {
        end_ind = mid_ind;
    }
    else {
        start_ind = mid_ind + 1;
    }
    
    return binary_search_recursion(data_array, target, start_ind, end_ind);
}

int main(int argc, char* argv[]) {

    cout << "Hello World!!!!\n" << endl;
    
    int capacity = 10;
    unique_ptr<int[]> data_array(new int[capacity]);
    
    // Put values into the data_array
    int fill_upto = 5;
    for (size_t i = 0; i < fill_upto; i++){
        data_array[i] = 2*i;
    }
    
    // Read values from the data_array
    cout << "after filling " << fill_upto << " cells: " << endl;
    for (size_t i = 0; i < fill_upto; i++){
        std::cout << data_array[i] << ", ";
    }
    cout << endl;
    
    // Call fill_data_array method
    fill_data_array(data_array, capacity, fill_upto);
    
    // Read values again from the data_array after latest modification
    cout << "\nafter filling in all the cells:" << endl;
    for (size_t i = 0; i < capacity; i++){
        std::cout << data_array[i] << ", ";
    }
    cout << endl;
    
    // Now perform binary search on that array
    cout << "\noutput of binary search:" << endl;
    int target_element = -10;
    int target_index = binary_search(data_array, target_element, 0, capacity-1);
    cout << target_element << " is at index " << target_index << endl;
    
    // Now perform binary search on that array
    cout << "\noutput of recursive binary search:" << endl;
    int target_element2 = 16;
    int target_index2 = binary_search_recursion(data_array, target_element2, 0, capacity-1);
    cout << target_element2 << " is at index " << target_index2 << endl;
    
    return 0;
}
