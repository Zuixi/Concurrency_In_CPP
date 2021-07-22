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

class hierarchical_mutex {
    std::mutex internal_mutex;
    unsigned long const hierarchical_value;
    unsigned long previous_hierarchy_value;
    static std::thread_local unsigned long this_thread_hierarchy_value;

    void check_for_hierarchy_violation() {
        if (this_thread_hierarchy_value <= hierarchical_value) 
        {
            throw std::logic_error("mutex hierarchy violated");
        }
    }

    void update_hierarchy_value() {
        previous_hierarchy_value = this_thread_hierarchy_value;
        this_thread_hierarchy_value = hierarchical_value;
    }

public:
    explicit hierarchical_mutex(unsigned long value): hierarchical_value(value), previous_hierarchy_value(0) {}

    void lock() {
        check_for_hierarchy_violation();
        internal_mutex.lock();
        update_hierarchy_value();
    }

    void unlock() {
        this_thread_hierarchy_value = previous_hierarchy_value;
        internal_mutex.unlock();
    }

    bool try_lock() {
        check_for_hierarchy_violation();
        
        if (!internal_mutex.try_lock())
            return false;
        
        update_hierarchy_value();
        return true;
    }
};

#endif