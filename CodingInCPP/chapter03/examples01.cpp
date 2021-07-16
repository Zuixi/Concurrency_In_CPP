#include "..\\include\\common.h"

#include <mutex>
#include<algorithm>
#include<list>

// 声明一个全局变量和全局互斥量
std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int value){
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(value);
}

bool list_contains(int value_to_find){
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}

int main(){

    std::thread writeData(add_to_list, 11);
    writeData.join();
    std::cout << "size of list is " << some_list.size() << std::endl;

    std::thread readData(list_contains, 11);    // 这里应该读取入口函数的返回值的，我还不会，难顶
    readData.join();

    return 0;
}