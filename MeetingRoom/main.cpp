#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int numMeetingRoom(int interval[3][2])
{
    int num_room = 0;
    
    // Create a priority queue and store all the meeting intervals in ascending order of the
    // starting time of the meetings.
    auto cmp = [](vector<int> first, vector<int> second){ return first[0] > second[0]; };
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> pq(cmp);
    
    for (int i=0; i<3; i++)
        pq.push(std::vector<int> ({interval[i][0],interval[i][1]}));
    
//    // Print the elements of the priority queue
//    std::vector<int> temp;
//    while (!pq.empty())
//    {
//        temp = pq.top();
//        std::cout << temp[0] << "," << temp[1] << std::endl;
//        pq.pop();
//    }
    
    // Initialize a priority queue in ascending order of the finishing time of the meetings
    auto cmp2 = [](vector<int> first, vector<int> second){ return first[1] > second[1]; };
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp2)> meeting_room(cmp2);
    meeting_room.push(pq.top());
    pq.pop();
    
    std::vector<int> ongoing_earliest_finish, current_finish;
    while (!pq.empty())
    {
        ongoing_earliest_finish = meeting_room.top();
        meeting_room.pop();
        
        current_finish = pq.top();
        pq.pop();
        
        if (current_finish[1] > ongoing_earliest_finish[1])
        {
            ongoing_earliest_finish[1] = current_finish[1];
            meeting_room.push(ongoing_earliest_finish);
        }
        else
        {
            meeting_room.push(ongoing_earliest_finish);
            meeting_room.push(current_finish);
        }
    }
    return meeting_room.size();
}

int main(int argc, char** argv) {
    ///////////////////// EXAMPLE 1 //////////////////////////
    // Given array of meeting intervals
    int interval[3][2] = {{0,30}, {5,10}, {15,20}};
    
    // call numMeetingRoom
    int num_meeting_room = numMeetingRoom(interval);
    std:cout << "Number of meeting rooms to be alloted: " << num_meeting_room << std::endl;
    
    //////////////////// EXAMPLE 2 ///////////////////////////
    // Given array of meeting intervals
    int interval2[2][2] = {{7,10}, {2,4}};
    
    // call numMeetingRoom
    int num_meeting_room2 = numMeetingRoom(interval2);
    std::cout << "Number of meeting rooms to be alloted: " << num_meeting_room2 << std::endl;
    
    return 0;
}

