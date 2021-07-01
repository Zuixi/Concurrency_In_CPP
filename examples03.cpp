#include "..\\include\\common.h"

int main(){
    int data = 0;
    func my_func(data);

    std::thread t(my_func);
    thread_guard g(t);

    std::cout << "print something in current thread\n";
    return 0;
}