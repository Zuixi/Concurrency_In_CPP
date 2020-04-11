#pragma once

#include <iostream>
#include <thread>

namespace ConcurrencyONE
{
    namespace _1_1
    {
        void hello()
        {
            std::cout << "Hello Concurrency World in Chapter 1" << std::endl;
        }

        void test()
        {
            std::thread t(hello);    // 构造一个新线程
            t.join();
            
        }
    }

    namespace _1_2
    {
        void foo()
        {
            std::cout << "foo function do nothing\n" << std::endl;
        }

        void bar(int x)
        {
            std::cout << "bar function use number " << x << " do nothing\n" << std::endl;
        }

        void TwoThreadTest()
        {
            std::thread first(foo);
            std::thread second(bar, 0);

            std::cout << "main, foo and bar now execute concurrently...\n";

            // 同步线程
            first.join();
            second.join();

            std::cout << "foo and bar completed.\n";
        }
    }

    namespace _1_3
    {
        void hello()
        {
            std::cout << "Hello Concurrent World, thread_id = " << std::this_thread::get_id() << "\n";
        }

        void hello2(int i)
        {
            std::cout << "before main, i = " << i << " ,thread_id = " << std::this_thread::get_id() << std::endl;
        }
    }


}