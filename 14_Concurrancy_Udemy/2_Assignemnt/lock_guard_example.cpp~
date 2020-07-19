#include <iostream>
#include <mutex>
#include <list>
#include <thread>

/* //////////// Read me //////////////////
The class LOCK_GUARD is a mutex wrapper. When a lock_guard object
is created, it takes the ownership of the mutex it is given. When control leaves the scope in which lock_guard object was created, the lock_guard is destructed and the mutex is released.
*/

std::list<int> my_list;
std::mutex m;

void add_to_list(int const & x) {
	std::lock_guard<std::mutex> lg(m);
	my_list.push_front(x);
}

void size(){
	std::lock_guard<std::mutex> lg(m);
	int size = my_list.size();
	std::cout << "size of the list is: " << size << std::endl;
}

int main(){
	std::thread thread_1(add_to_list, 4);
	std::thread thread_2(add_to_list, 8);
	
	thread_1.join();
	thread_2.join();	
}
