#include <iostream>
#include <vector>
#include <algorithm> // for min
#include<climits> // for INT_MAX 

using namespace std;

int find_num_rot(int target, std::vector<int> &array1, std::vector<int> &array2)
{
    int num_rot;
    
    for(size_t i=0; i<array1.size(); i++)
    {
        if (target != array1[i])
        {
            if (target == array2[i])
            {
                num_rot++;
            }
            else
            {
                return INT_MAX; // return some big number
            }
        }
    }
    return num_rot;
}

int minDominoRotations(std::vector<int> &A, std::vector<int> &B)
{
    int num_rot1, num_rot2, num_rot3, num_rot4;
    
    num_rot1 = find_num_rot(A[0], A, B);
    num_rot2 = find_num_rot(A[0], B, A);
    num_rot3 = find_num_rot(B[0], B, A);
    num_rot4 = find_num_rot(B[0], A, B);
    
    return min(min(min(num_rot1, num_rot2),num_rot3),num_rot4);
}

int main(int argc, char** argv) {
    std::vector<int> A = {2, 1, 2, 4, 2, 2}; 
    std::vector<int> B = {5, 2, 6, 2, 3, 2};
    
    int min_rotations = minDominoRotations(A, B);
    std::cout << "Minimum domino rotation: " << min_rotations << std::endl;
    return 0;
}

