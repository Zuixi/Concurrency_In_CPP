#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <thread>
#include <string>
#include <vector>

// define some class

// 线程访问数据不安全
struct func
{
    int &data;
    
    func(int &data):data(data){}

    void operator() (){
        for(unsigned int j = 0; j < 100000; ++j){
            std::cout << "other currency cout " << data << std::endl;
        }
    }
};


class thread_guard{
    std::thread &t;
public:
    explicit thread_guard(std::thread &t): t(t){}   // 防止隐式转换的发生

    ~thread_guard(){
        if (t.joinable()){
            t.join();
        }
    }

    thread_guard(thread_guard const&)=delete;    //禁用拷贝构造函数
    thread_guard& operator= (thread_guard const&) = delete;    // 禁用拷贝复制运算符
};

#endif