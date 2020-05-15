#pragma once
#include <iostream>
#include <mutex>
#include <deque>
#include <cassert>
#include <cstddef>
#include "Color.h"

namespace Competetion_Shara_Data
{
    // ����ʹ����ģ��Ԫ���Ŷ
    // && Ϊ���õ�����
    void do_something(int val)
    {
        std::cout << green << "val = " << val << std::endl;
    }

    // ����һ��ģ����

    /**************************************************************************
    * stack�Ľӿ��Դ�������������������ⲻ�������ڻ��ڻ�����ʵ�ֵĽӿ���,
    * ������ʵ�ֵĽӿ���,�����������ɻ���������ǽӿڵ�����,����ʵ�ַ�ʽ�޹�:
    * ��Ȼempty()��size()��ʹ�ڱ�����ʱ������ȷ���,�������ǲ��ɿ���;�����Ƿ���
    * ��,�����߳̾Ϳ������ɵط���ջ,���ҿ���push()�����Ԫ�ص�ջ��,Ҳ����pop()һЩ��
    * ��ջ�е�Ԫ�ء������Ļ�,֮ǰ��empty()��size()�õ��Ľ�����������ˡ�
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

        // ���߳�,�ڴ˲���ȫ���Կ�ջ����top() ��δ������Ϊ
        if (!IntStack.empty())
        {
            // ����ɾ��ջ�����
            int const val = IntStack.top();
            IntStack.pop();

            do_something(val);
        }
    }


}