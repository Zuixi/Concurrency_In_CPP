#pragma once

#include <list>
#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>
#include <cassert>

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