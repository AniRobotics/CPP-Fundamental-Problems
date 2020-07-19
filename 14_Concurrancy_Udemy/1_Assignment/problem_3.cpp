#include <iostream>
#include <thread>
#include <chrono>
#include <queue>

/* Read me
Compile instruction: g++ -W -Wall -std=c++11 -o problem_3 problem_3.cpp -pthread
Execution instruction: ./problem_3

This code prompts for enterning one of the numbers : 1, 2, 100, 200
If 1 or 100 is entered, q_worker is updated. If 2 or 200 is entered q_cleaning is
updated. 1 and 2 commands the corresponding threads to continue running while 100 and 200 commands to stop the corresponding threads.

If any of the treads STOPs working then the done_worker or done_cleaning flags 
are raised to be true.

When done_worker and done_cleaning both the flags are set true, the program exits.   
*/


std::queue<int> q_worker;
std::queue<int> q_cleaning;
int command;
bool done_worker = false;
bool done_cleaning = false;

void worker(){
	bool done = false;
	while(!done){
		// printf("Working ... \n");
		if (!q_worker.empty()) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			if (q_worker.front() == 100){
				// printf("\nStop command received for thread_worker\n");
				done = true;
			}
			q_worker.pop();
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
	}
	done_worker = true;
}

void cleaning(){
	bool done = false;
	while(!done){
		// printf("Cleaning ... \n");
		if (!q_cleaning.empty()) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			if (q_cleaning.front() == 200){
				// printf("\nStop command received for thread_cleaning\n");
				done = true;
			}
			q_cleaning.pop();
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
	}
	done_cleaning = true;
}

void implement_iterative_thread(){

	std::thread thread_worker(worker);
	printf("WORK thread started\n");
	std::thread thread_cleaning(cleaning);
	printf("CLEAN thread started\n");
	
	while(!done_worker || !done_cleaning){
		printf("Give command 1, 2, 100, 200: ");
		std::cin >> command;
		
		if (command == 1 || command == 100) {
			q_worker.push(command);
		}
		
		if (command == 2 || command == 200) {
			q_cleaning.push(command);
		}
		// Wait for 3s so that all other threads stops working
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
	
	thread_worker.join();
	thread_cleaning.join();
	printf("Both WORK and CLEAN thread STOPPED \n");
	
}

int main(){

	std::cout << "Number of maximum threads: " << std::thread::hardware_concurrency() << std::endl;

	std::thread thread_1(implement_iterative_thread);
	thread_1.join();

	return 0;
	
}

