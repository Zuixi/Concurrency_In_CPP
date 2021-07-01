#include <iostream>
#include <thread>

void hello(){
    std::cout << "print hello in another thread" << std::endl;
}

int main(){

    using namespace std;
    std::thread t{hello};
    t.join();

    return 0;
}