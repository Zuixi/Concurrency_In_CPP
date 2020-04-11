#pragma once

#include <thread>
#include <iostream>

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