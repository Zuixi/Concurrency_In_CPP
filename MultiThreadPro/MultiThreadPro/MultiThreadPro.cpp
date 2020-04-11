// MultiThreadPro.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <type_traits>
#include <thread>
#include <vector>
#include <algorithm>
#include <forward_list>
#include <string>
#include "Foo.h"
#include "DP.h"
#include "template.h"
#include "ModernC/DelegateConstructor.h"

int Num = 6;
char str[7] = "ACDBCB";
void solvestr()
{
    int begin = 0;
    int end = Num - 1;

    while (begin <= end)
    {
        bool isLeft = false;

        // 用一个i作为哨兵控制S移动字符的能力
        for (int i = 0; begin + i <= end; i++)
        {
            if (str[begin + i] < str[end - i])
            {
                isLeft = true;
                break;
            }
            else
            {
                isLeft = false;
                break;
            }
        }

        if (isLeft)
        {
            std::cout << str[begin++];
        }
        else
        {
            std::cout << str[end--];
        }
    }

    std::cout << std::endl;
}


int count = 0;
void doSomeWork()
{
    std::cout << "The doSomeWork function is running on another thread." << std::endl;
    int data = count++;
    // Pause for a moment to provide a delay to make
    // threads more apparent.
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = std::to_string(data);
    std::cout << "The function called by the worker thread has ended. " + str << std::endl;
}

size_t memoryArray[256];

int fib(int n)
{
     if (n <= 1)
        return n;
    if (memoryArray[n] != 0)
        return memoryArray[n];

    return memoryArray[n] = fib(n - 1) + fib(n - 2);
}

void foo(char*)
{
    std::cout << "Hello NULL" << std::endl;
}

void foo(int)
{
    std::cout << "Hello INT" << std::endl;
}

#define LEN 10

int leg_foo()
{
    return 2;
}

constexpr int len_foo_constexpr()
{
    return 5;
}

constexpr int fibonacci(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}


template <typename T>
T Add(T t1, T t2)
{
    return t1 + t2;
}

int main()
{
    //std::vector<std::thread> threads;

    //for (int i = 0; i < 7; ++i) {

    //    threads.push_back(std::thread(doSomeWork));
    //    std::cout << "The Main() thread calls this after starting the new thread" << std::endl;
    //}

    //for (auto& thread : threads) {
    //    thread.join();
    //}

    //int n;
    //std::cin >> n;
    //int i = 0;
    //while(i < n)
    //{
    //    int a;
    //    std::cin >> a;
    //    std::cout << "fib(" << a << ") = " << fib(a) << std::endl;
    //}


    //solvestr();
    //if (std::is_same<decltype(NULL), decltype(0)>::value)
    //    std::cout << "NULL == 0" << std::endl;
    //if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
    //    std::cout << "NULL == (void*)0" << std::endl;
    //if (std::is_same<decltype(NULL), decltype(nullptr)>::value)
    //    std::cout << "NULL == nullptr" << std::endl;

    //foo(0);    //将会调用foo(int)
    //foo(NULL);    //还是会调用foo(int)
    //foo(nullptr);    //将会调用foo（char*)

    //char* ch = NULL;

    //char arr_1[10];
    //char arr_2[LEN];

    //int length = 10;
    ////char arr_3[length];   not illeagal

    //const int len_2 = length + 1;
    ////char arr_4[len_2];    not illeagal

    //constexpr int len_3 = 1 + 2;
    //char arr_5[len_3];

    //std::cout << fibonacci(10) << std::endl;


    //std::vector<int> vec = { 1,2,3,4 };

    //// 在vec中寻找2的位置
    //const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);

    //if (itr != vec.end())
    //{
    //    *itr = 3;    // 将2变成3
    //}

    //if (std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end())
    //{
    //    *itr = 4;
    //}


    //for (std::vector<int>::iterator element = vec.begin(); element != vec.end(); element++)
    //{
    //    std::cout << *element << " ";
    //}

    //std::cout << std::endl << "using auto with C++17" << std::endl;
    //for (const auto element : vec)
    //{
    //    std::cout << element << " ";
    //}

    // 在C++ 11之前
    int arr[2] = { 1,2 };

    Foo foo(1, 2);
    std::vector<int> vec = { 2,3,4 };

    MagicFoo magicFoo = { 1,3,4 };
    
    for (auto ele : magicFoo.vec)
        std::cout << ele << " ";

    std::cout << std::endl;

    std::cout << "No Error" << std::endl;

    std::cout << "using template function" << std::endl;

    std::cout << "2 + 3 = " << Add<int>(2, 3) << std::endl;
    std::cout << " 2.4 + 1.2 = " << Add<double>(2.4, 1.2) << std::endl;


    //// 背包问题的解决
    //DP test = { 2,1,3,2,3,2,4,2 };
    //test.SetN(4);
    //test.SetW(5);
    //test.ReturnRes(0, 5);
    //test.PrintRes();

    //char strname[20];
    //strcpy_s(strname,"");
    //std::forward_list<char*, std::allocator<char*>> strlist;
    //std::vector<char*> strvec;

    //while (fgets(str,20,stdin) != NULL)
    //{
    //   // strlist.assign(str);
    //    strvec.push_back(str);
    //}

    //std::cout <<"Hello" << std::endl;

    Print2(1, 2, 3, 4, "hello", true);

    Base pBase = Base(4);
    std::cout << pBase.value1 << std::endl;
    std::cout << pBase.value2 << std::endl;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
