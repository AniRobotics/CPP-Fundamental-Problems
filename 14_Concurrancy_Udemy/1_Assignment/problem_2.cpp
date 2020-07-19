#include <iostream>
#include <thread>
#include <chrono>

// Cleaning function
void cleaning(){
	printf("thread_id: %d. Type: Cleaning \n", std::this_thread::get_id());
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	printf("Cleaning complete \n");
}

// Full speed function
void full_speed(){
	printf("thread_id: %d. Type: Full-Speed \n", std::this_thread::get_id());
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	printf("Full speed complete \n");
}

// Stop function
void stop(){
	printf("thread_id: %d. Type: Stop \n", std::this_thread::get_id());
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	printf("Stop complete \n");
}

// thead to get console input and command accordingly
void get_console_input(){
	int command_ip;
	printf("Give commands using 1, 2, 3, 100: ");
	std::cin >> command_ip;

	while (true) {
		if (command_ip == 1){
			std::thread thread_cleaning(cleaning);
			thread_cleaning.detach();
			printf("Cleaning thread detached \n");
		}
		else if (command_ip == 2){
			std::thread thread_fullspeed(full_speed);
			thread_fullspeed.join();
		}
		else if (command_ip == 3){
			std::thread thread_stop(stop);
			thread_stop.join();
		}
		else if(command_ip == 100){
			printf("STOP is commanded\n");
			break;
		}
		else {
			printf("INVALID command\n");
			break;
		}
		// std::this_thread::sleep_for(std::chrono::seconds(1));
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		printf("-------------------- \n");
		printf("Give commands using 1, 2, 3, 100: ");
		std::cin >> command_ip;
	}
	printf("Exiting console input thread\n");
}

int main(int argc, char** argv){

	std::thread thread_1(get_console_input);
	thread_1.join();
	
	printf("thread_id: %d. Type: Main thread \n", std::this_thread::get_id());
	printf("Exiting main thread \n");
	return 0;
}
