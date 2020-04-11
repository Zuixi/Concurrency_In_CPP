#pragma once
#include <iostream>

struct Base {
    virtual void foo(int);
};

// SubBase�е�foo�п������������ظ����foo�������ֻ�����ֱ����дһ��������ͬ�ĺ���
// �������������һ�����⣺��������foo������ɾ���ˣ���ôSubBase���foo�����Ͳ�������д�麯���ˣ�����һ����ͨ�ĺ�����
struct SubBase :Base {
    void foo();    // overload foo function in Base, or just write a new function
};



// Ϊ�˽����������⣬C++11������override��final�����ؼ���
// 1. �����Ҫ��дһ����������ô����ʹ��override�ؼ��ֽ���������֮����������жϸ������Ƿ���ж�Ӧ���麯����û�еĻ����޷�����ͨ��

struct OverBase
{
    virtual void foo(int);
};

struct SubOverBase :OverBase
{
    virtual void foo(int) override; //�Ϸ�����
    //virtual void foo(double) override;   ������û�ж�Ӧ�ĺ����������������Ϸ�
};


// 2. final�ؼ������������಻�ڱ��̳л��߽�ֹ�����麯��
struct FinalBase
{
    virtual void foo(int) final;
 };

struct SubFinalBase1 final :FinalBase    // legal statement
{

};

/*
* �Ƿ�����ʾ��
struct SubFinalBase2 :SubFinalBase1    // �Ƿ����壬��ʹ��final�ؼ������Ƽ̳�
{

};

struct SubFinalBase3 :FinalBase
{
    void foo(int);    // �Ƿ����ף�foo����ʹ��final��������
};

*/

class Magic
{
public:
    Magic() = default;    // ʹ��Ĭ�Ϲ��캯��
    Magic& operator=(const Magic&) = delete;    // �ܾ�ʹ��
    Magic(int magic_number);
};

enum class new_enum : unsigned int
{
    value1,
    value2,
    value3 = 100,
    value4 = 100
};