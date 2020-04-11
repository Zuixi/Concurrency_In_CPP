#pragma once
#include <iostream>
#include <string>
#include <initializer_list>

class Base
{
public:
    int value1;
    int value2;

public:
    Base()
    {
        value1 = 1;
    }

    // 使用Delegete Base方法，用来简化code
    Base(int value) :Base()
    {
        value2 = value;
    }
};


// 在构造函数的继承下的优化
class SubBase :public Base
{
public:
    using Base::Base;    // 继承构造函数
};


