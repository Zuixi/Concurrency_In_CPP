#pragma once
#include <iostream>
#include <cassert>
#include <list>
#include <string>
#include <mutex>


namespace Shara_Data_With_Reference
{
    // 对于要共享的数据不能传入指针或者引用，因为有可能会造成数据不安全的存在
    // 共享数据
    class Some_Data
    {
        int val = 0;
        std::string str = "hello";

    public:
        Some_Data()
        {
            std::cout << "val = " << val << "\tstr = " << str << std::endl;
        }
        void do_something()
        {
            ++val;
            str += "modify";
            std::cout << "val = " << val << "\tstr = " << str << std::endl;
        }
    };


    // 清理数据
    class Data_Wrapper
    {
    private:
        Some_Data m_data;
        std::mutex m_lock;
        
    public:
        template<class Function>
        void process_data(Function func)
        {
            std::lock_guard<std::mutex> guard(m_lock);
            // 根据传入的函数对 data进行处理，data不能传引用。否则容易泄露受保护数据的地址。
            func(m_data);
        }
    };


    Some_Data* unprotectedData;

    /***************
    勿将受保护数据的指针或引用传递到互斥锁作用域之外:
    无论是函数返回值,还是存储在外部可见内存,亦或是以参数的形式传递到用户提供的函数中去。
    ****************/

    // 传递了欲保护的数据data作为函数参数。malicious:adj.	恶意的
    void malicious_function(Some_Data& protected_data) 
    {
        unprotectedData = &protected_data; //泄露了成员地址。此后全局变量可以访问私有变量data而不受互斥锁限制。
    }

    void foo()
    {
        Data_Wrapper x;
        //传入函数指针
        x.process_data(malicious_function);
        // 尝试修改data的数据
        unprotectedData->do_something();
    }

}