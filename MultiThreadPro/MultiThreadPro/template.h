#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// varibale paremeter and constexpr for if statement
// Note:constexpt shod use with C++17
template<class T0, class...T1>
void Print2(T0 value, T1...args) {
    if constexpr (sizeof...(args) > 0)  //在编译阶段就得到处理，即使是假也不会处理else里面的语句
        Print2(args...);
    else
        std::cout << value << std::endl;
}

// black magic of initializaton list
template<class T,class... Ts>
auto Print3(T value, Ts... args)
{
    std::cout << value << std::endl;
    std::initializer_list<T>{([&args]
    {
        std::cout << args << std::endl;
    }(), value)...
    };
}