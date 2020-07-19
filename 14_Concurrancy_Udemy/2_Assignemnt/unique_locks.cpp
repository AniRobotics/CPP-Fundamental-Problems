#include <iostream>
#include <thread>
#include <mutex>

/* //////////// Read me /////////////////
	- unique_lock is  general-purpose mutex ownership wrapper.
	- it can be used to manage mutexes like lock_guard objects
	- However unlike lock_guard object it does not have to acquire
	  the lock for the associated mtex in the construction.
	- unique_locks are neither copy constructable nor copy assignable.
	- but they are move constructable and move assignable. 
*/


