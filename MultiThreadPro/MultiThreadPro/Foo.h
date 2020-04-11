#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>
class Foo
{
public:
    int value_a;
    int value_b;

    Foo(int a, int b) :value_a(a), value_b(b) {}
};

class MagicFoo
{
public:
    std::vector<int> vec;

    MagicFoo(std::initializer_list<int> list)
    {
        for (auto ele : list)
            vec.push_back(ele);
    }
};


