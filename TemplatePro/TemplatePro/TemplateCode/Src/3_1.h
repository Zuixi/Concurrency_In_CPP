#pragma once

#include <list>
#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>
#include <cassert>

namespace Share_Data
{

    /****************************
    线程间共享数据->
    当访问共享数据前，使用互斥量将相关数据锁住，在当访问结束后，在将数据解锁。线程库需要保证
    当一个线程使用特定互斥量锁住共享数据的时候，其他线程想要访问锁住的数据的时候都必须等到之
    前那线程对数据进行解锁后，才能进行访问，这就保证了所有线程能看到共享数据，而不破坏变量

    C++中通过std::mutex创建互斥量，通过调用成员函数lock和unlock进行加锁和解锁。在C++11之后不在
    推荐使用着各种方法，因为收到lock和unlock会有存在许多犯错的机会；
    std::lock_guard在其构造的时候会锁住提供的互斥量，在析构时候进行解锁，从而保证lock和unlock
    的正确使用
    
    
    */
    std::list<int> some_list;
    std::mutex some_mutex;

    void add_to_list(int new_value)
    {
        // std::lock_guard 传入mutex对象，传入的对象会被当前线程锁住，当lock——guard对象会析构时，mutex会自动解锁
        std::lock_guard<std::mutex> guard(some_mutex);
        some_list.push_back(new_value);
    }

    bool list_contains(int key)
    {
        std::lock_guard<std::mutex> guard(some_mutex);
        // 使用find算法某个元素是否存在
        return std::find(some_list.begin(), some_list.end(), key) != some_list.end();
    }

    bool isContained()
    {
        for (int i = 0; i < 1000; i++)
        {
            if (std::find(some_list.begin(), some_list.end(), i) == some_list.end())
                return false;
        }

        return true;
    }
}