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
            int some_local_state = 0;    // ������ȴ��̣߳��ͱ��뱣֤�߳̽���֮ǰ�ɷ������ݵ���Ч��
            func my_func(some_local_state);

            std::thread my_thread(my_func);

            // �����̣߳���Ҫ��ȷ��Ҫ�ȴ��߳̽���(join)�������߳���������(detach)
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
            // ����һ���ṹ�����
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
            ����join,�����߳���صĴ洢���֣�����std::thread���������Ѿ���ɵ��߳����κι���
            Ҳ����˵����һ��thread��ֻ��ʹ��һ��join��һ��ʹ�ù�join����ôthread����Ͳ����ټ����ˣ�
            ������ʹ��joinable()ʱ���᷵��һ��false
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
    �̼߳乲������->
    �����ʹ�������ǰ��ʹ�û����������������ס���ڵ����ʽ������ڽ����ݽ������߳̿���Ҫ��֤
    ��һ���߳�ʹ���ض���������ס�������ݵ�ʱ�������߳���Ҫ������ס�����ݵ�ʱ�򶼱���ȵ�֮
    ǰ���̶߳����ݽ��н����󣬲��ܽ��з��ʣ���ͱ�֤�������߳��ܿ����������ݣ������ƻ�����

    C++��ͨ��std::mutex������������ͨ�����ó�Ա����lock��unlock���м����ͽ�������C++11֮����
    �Ƽ�ʹ���Ÿ��ַ�������Ϊ�յ�lock��unlock���д�����෸��Ļ��᣻
    std::lock_guard���乹���ʱ�����ס�ṩ�Ļ�������������ʱ����н������Ӷ���֤lock��unlock
    ����ȷʹ��


    */
    std::list<int> some_list;
    std::mutex some_mutex;

    void add_to_list(int new_value)
    {
        // std::lock_guard ����mutex���󣬴���Ķ���ᱻ��ǰ�߳���ס����lock����guard���������ʱ��mutex���Զ�����
        std::lock_guard<std::mutex> guard(some_mutex);
        some_list.push_back(new_value);
    }

    bool list_contains(int key)
    {
        std::lock_guard<std::mutex> guard(some_mutex);
        // ʹ��find�㷨ĳ��Ԫ���Ƿ����
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