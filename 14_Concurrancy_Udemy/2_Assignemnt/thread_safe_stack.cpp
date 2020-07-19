#include <iostream>
#include <thread>
#include <mutex>
#include <stack>

/* A thread safe stack is implemented is OOP style. The implemented class methods are 1. empty, 2. size, 3. top, 4. push, 5. pop.
*/

template <typename T>
class thread_safe_stack{
	std::stack<T> stk;
	std::mutex m;
public:
	void push(T element){
		std::lock_guard<std::mutex> lg(m);
		stk.push(element);
	}
	
	void pop(){
		std::lock_guard<std::mutex> lg(m);
		stk.pop();
	}
	
	T& top(){
		std::lock_guard<std::mutex> lg(m);
		return stk.top();
	}
	
	bool empty(){
		std::lock_guard<std::mutex> lg(m);
		return stk.empty();
	}
	
	size_t size(){
	}
};


