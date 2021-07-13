#include <iostream>
#include <thread>
#include <mutex>

class some_data{
    int a;
    std::string str;

public:
    void do_something(){
        std::cout << "do something" << std::endl;
    }
};

class data_wrapper{
private:
    some_data data;
    std::mutex mutex;

public:
    template<typename Function>
    void process_data(Function func){
        std::lock_guard<std::mutex> l(mutex);
        func(data);
    }
};

// 定义一个全局变量用来存取data_wrapper对象的指针
some_data* unprocted = nullptr;
void malicious_func(some_data &protected_data){
    unprocted = &protected_data;
}

int main(){
    data_wrapper demo;
    demo.process_data(malicious_func);
    unprocted->do_something();    // 这个指针可以绕过互斥量进行数据访问，就容易导致竞争
    return 0;
}