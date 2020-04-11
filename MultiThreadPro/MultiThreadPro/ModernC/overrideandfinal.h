#pragma once
#include <iostream>

struct Base {
    virtual void foo(int);
};

// SubBase中的foo有可能是用来重载父类的foo函数，又或者是直接新写一个名字相同的函数
// 但是这样会存在一个问题：如果父类的foo函数被删除了，那么SubBase里的foo函数就不再是重写虚函数了，而是一个普通的函数了
struct SubBase :Base {
    void foo();    // overload foo function in Base, or just write a new function
};



// 为了解决上面的问题，C++11引入了override和final两个关键字
// 1. 如果需要重写一个函数，那么可以使用override关键字进行声明，之后编译器会判断父类中是否会有对应的虚函数，没有的话则无法编译通过

struct OverBase
{
    virtual void foo(int);
};

struct SubOverBase :OverBase
{
    virtual void foo(int) override; //合法声明
    //virtual void foo(double) override;   父类中没有对应的函数，所以声明不合法
};


// 2. final关键字用来限制类不在被继承或者禁止重载虚函数
struct FinalBase
{
    virtual void foo(int) final;
 };

struct SubFinalBase1 final :FinalBase    // legal statement
{

};

/*
* 非法定义示例
struct SubFinalBase2 :SubFinalBase1    // 非法定义，类使用final关键字限制继承
{

};

struct SubFinalBase3 :FinalBase
{
    void foo(int);    // 非法顶底，foo函数使用final限制重载
};

*/

class Magic
{
public:
    Magic() = default;    // 使用默认构造函数
    Magic& operator=(const Magic&) = delete;    // 拒绝使用
    Magic(int magic_number);
};

enum class new_enum : unsigned int
{
    value1,
    value2,
    value3 = 100,
    value4 = 100
};