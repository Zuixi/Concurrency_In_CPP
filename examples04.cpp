#include "..\\include\\common.h"

// 验证线程中传递参数的方式
void update_data(int &data){
    ++data;
}

int main(){
    int data = 1;

    std::cout << "origin data is "<< data << std::endl;
    update_data(data);
    std::cout << "update data, data is " << data << std::endl;

    // 希望使用线程更新数据data
    std::thread t(update_data, std::ref(data));     // std::thread arguments must be invocable after conversion to rvalues
    t.join();
    
    if (data != 2)
        std::cout << "with new thread update data, data is " << data << std::endl;
    else
        std::cout << "new thread not update data successly" << std::endl;

    return 0;
}