#include <iostream>
#include <thread>

class Background_Task
{
public:
	void operator() (){
		doSomething();
		doSomethingElse();
	}

	inline void doSomething(){
		std::cout << "Do something\n";
	}

	inline void doSomethingElse(){
		std::cout << "Do something else\n";
	}
};

int main(){
	Background_Task f;
	// f is object
	std::thread t{Background_Task()};    // launch thread
	t.join();    // terminate before main exit

	// std::thread my_thread(Background_Task);
	// my_thread.join();
	
	return 0; 
}