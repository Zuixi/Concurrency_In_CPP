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

    // ʹ��Delegete Base������������code
    Base(int value) :Base()
    {
        value2 = value;
    }
};


// �ڹ��캯���ļ̳��µ��Ż�
class SubBase :public Base
{
public:
    using Base::Base;    // �̳й��캯��
};


