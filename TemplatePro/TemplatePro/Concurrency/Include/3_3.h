#pragma once
#include <iostream>
#include <mutex>
#include <deque>
#include <cassert>
#include <cstddef>
#include "Color.h"

namespace Competetion_Shara_Data
{
    // 这里使用了模板元编程哦
    // && 为引用的引用
    void do_something(int val)
    {
        std::cout << green << "val = " << val << std::endl;
    }

    // 定义一个模板类

    /**************************************************************************
    * stack的接口仍存在条件竞争。这个问题不仅存在于基于互斥量实现的接口中,
    * 在无锁实现的接口中,条件竞争依旧会产生。这是接口的问题,与其实现方式无关:
    * 虽然empty()和size()即使在被调用时返回正确结果,但其结果是不可靠的;当它们返回
    * 后,其他线程就可以自由地访问栈,并且可能push()多个新元素到栈中,也可能pop()一些已
    * 在栈中的元素。这样的话,之前从empty()和size()得到的结果就有问题了。
    **************************************************************************/
    template<class T, class Container = std::deque<T>>
    class stack
    {
    public:
        explicit stack(const Container&) {};

        explicit stack(Container && = Container())
        {

        };

        template<class Allocator>
        explicit stack(const Allocator&) {};

        template<class Allocator>
        stack(const Container&, const Allocator&) {};

        template<class Allocator>
        stack(Container&&, const Allocator&) {};

        template<class Allocator>
        stack(stack&&, const Allocator&) {};

        bool empty() {};

        size_t size() const {};

        T& top() const {};

        void push(T const&) {};

        void push(T const&&) {};

        void pop() {};

        void swap(stack&&) {};

    };

    void only_single_thread()
    {
        stack<int> IntStack;

        // 多线程,在此不安全：对空栈调用top() 是未定义行为
        if (!IntStack.empty())
        {
            // 存在删空栈的情况
            int const val = IntStack.top();
            IntStack.pop();

            do_something(val);
        }
    }


}