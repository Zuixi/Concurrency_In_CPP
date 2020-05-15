#pragma once

#include <thread>
#include <iostream>
#include <list>
#include <mutex>
#include <algorithm>
#include <cassert>

namespace CONCURRENCY_TWO
{
    namespace _1_1
    {
        void do_something(int& i)
        {
            if (i < 1000)
            {
                printf("i = %d ", i);
            }
            else
            {
                std::cout << " out of range\n";
            }
            ++i;
        }

        struct func
        {
            int& i;

            func(int& i_) :i(i_) {}

            void operator() ()
            {
                for (unsigned j = 0; j < 1000; j++)
                {
                    do_something(i);
                }
            }
        };

        void oops()
        {
            int some_local_state = 0;    // 如果不等待线程，就必须保证线程结束之前可访问数据的有效性
            func my_func(some_local_state);

            std::thread my_thread(my_func);

            // 启动线程，需要明确是要等待线程结束(join)还是让线程自主运行(detach)
            my_thread.detach();
        }
    }

    namespace _2_2
    {
        void do_something(int& i)
        {
            printf("i = %d", i);
            ++i;
        }

        struct func
        {
            int& i;
            func(int& i_) : i(i_) {}

            void operator()()
            {
                for (unsigned int j = 0; j < 10000; j++)
                {
                    do_something(i);
                }
            }
        };

        void do_something_currenct_thread()
        {
            // do nothing  
        }

        void f()
        {
            int some_local_state = 0;
            // 传入一个结构体对象
            func my_func(some_local_state);
            std::thread t(my_func);

            try
            {
                do_something_currenct_thread();
            }
            catch (...)
            {
                t.join();
                throw;
            }
            t.join();

            /*
            调用join,清理线程相关的存储部分，这样std::thread对象不再与已经完成的线程有任何关联
            也就是说，对一个thread，只能使用一次join，一旦使用过join，那么thread对象就不能再加入了；
            当对其使用joinable()时，会返回一个false
            */
        }
    }

    namespace _2_3
    {
        class thread_guard
        {
            std::thread& t;

        public:
            explicit thread_guard(std::thread& t_) : t(t_) {}

            ~thread_guard()
            {
                if (t.joinable())
                {
                    t.join();    //
                }
            }

            thread_guard(thread_guard const&) = delete;

            thread_guard& operator=(thread_guard const&) = delete;

        };

        void do_something(int& i)
        {
            printf(" i = %d ", i);
            ++i;
        }

        struct func
        {
            int& i;

            func(int& i_) : i(i_) {}

            void operator()()
            {
                for (int j = 0; j < 10000; j++)
                {
                    do_something(i);
                }
            }
        };

        void do_something_in_current_thread()
        {}

        void f()
        {
            int some_local_state = 0;
            func my_func(some_local_state);

            std::thread t(my_func);
            thread_guard g(t);

            do_something_in_current_thread();
        }
    }
}


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