#pragma once
#include <iostream>
#include <vector>
#include <cassert>

namespace ClassTemplate
{
    template<class T>
    class Stack {
    private:
        std::vector<T> elements;

    public:
        void push(T const& elem);
        void pop();
        T const& top() const;    // return top element
        bool empty() const {
            return elements.empty();
        }
    };
}