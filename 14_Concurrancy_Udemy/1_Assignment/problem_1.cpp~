#include <iostream>
#include <thread>

void test(){
	printf("Hello from test\n");
}

void func_A(){
	printf("Hello from func_A\n");
	std::thread thread_C(test);
	thread_C.join();
}

void func_B(){
	printf("Hello from func_B\n");
}

int main(){
	std::thread thread_A(func_A);
	std::thread thread_B(func_B);
	
	thread_A.join();
	thread_B.join();
	
	printf("Hello from main\n");
	
	return 0;
}
