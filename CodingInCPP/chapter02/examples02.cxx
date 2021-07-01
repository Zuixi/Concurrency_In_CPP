
#include "..\\include\\common.h"


int main(){

    int locate_state = 1;
    func my_func(locate_state);

    // 这里会触发访问不安全数据
    std::thread t(my_func);
    t.detach();
    return 0;
}