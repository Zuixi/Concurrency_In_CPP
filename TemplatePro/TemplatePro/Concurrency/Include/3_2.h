#pragma once
#include <iostream>
#include <cassert>
#include <list>
#include <string>
#include <mutex>


namespace Shara_Data_With_Reference
{
    // ����Ҫ��������ݲ��ܴ���ָ��������ã���Ϊ�п��ܻ�������ݲ���ȫ�Ĵ���
    // ��������
    class Some_Data
    {
        int val = 0;
        std::string str = "hello";

    public:
        Some_Data()
        {
            std::cout << "val = " << val << "\tstr = " << str << std::endl;
        }
        void do_something()
        {
            ++val;
            str += "modify";
            std::cout << "val = " << val << "\tstr = " << str << std::endl;
        }
    };


    // ��������
    class Data_Wrapper
    {
    private:
        Some_Data m_data;
        std::mutex m_lock;
        
    public:
        template<class Function>
        void process_data(Function func)
        {
            std::lock_guard<std::mutex> guard(m_lock);
            // ���ݴ���ĺ����� data���д���data���ܴ����á���������й¶�ܱ������ݵĵ�ַ��
            func(m_data);
        }
    };


    Some_Data* unprotectedData;

    /***************
    ���ܱ������ݵ�ָ������ô��ݵ�������������֮��:
    �����Ǻ�������ֵ,���Ǵ洢���ⲿ�ɼ��ڴ�,������Բ�������ʽ���ݵ��û��ṩ�ĺ�����ȥ��
    ****************/

    // ������������������data��Ϊ����������malicious:adj.	�����
    void malicious_function(Some_Data& protected_data) 
    {
        unprotectedData = &protected_data; //й¶�˳�Ա��ַ���˺�ȫ�ֱ������Է���˽�б���data�����ܻ��������ơ�
    }

    void foo()
    {
        Data_Wrapper x;
        //���뺯��ָ��
        x.process_data(malicious_function);
        // �����޸�data������
        unprotectedData->do_something();
    }

}