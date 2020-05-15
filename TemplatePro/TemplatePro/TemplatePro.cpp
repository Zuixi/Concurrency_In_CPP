// TemplatePro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Include/templateFun.h"
#include "Concurrency/Include/1_1.h"
#include "Concurrency/Include/2_1.h"
<<<<<<< HEAD
#include "Concurrency/Include/3_1.h"
#include "APITest/copyFile.h"
=======
#include "Concurrency/Include/3_2.h"
>>>>>>> 8cf8b10ee6009d77dcc4afb7af11f124daa1ad37
#include <thread>

//std::thread::id master_thread;
//
//std::thread t0(ConcurrencyONE::_1_3::hello2, 2);


int main()
{
    
    //std::thread t(ConcurrencyONE::_1_3::hello);
    //master_thread = std::this_thread::get_id();
    //std::cout << "main thread id is " << master_thread << std::endl;
    //t.join();
    //t0.join();

    // 线程已经结束，函数还在访问局部变量
    //CONCURRENCY_TWO::_1_1::oops();
    //CONCURRENCY_TWO::_2_2::f();
    
    //CONCURRENCY_TWO::_2_3::f();

    /*std::vector<std::thread> vect;

<<<<<<< HEAD
    for (int i = 0; i < 1000; i++)
    {
        vect.push_back((std::thread(Share_Data::add_to_list, i)));
    }

    for (auto& val : vect)
    {
        val.join();
    }
=======
    //CONCURRENCY_TWO::_2_3::f();
    Shara_Data_With_Reference::foo();
    
>>>>>>> 8cf8b10ee6009d77dcc4afb7af11f124daa1ad37
    
    assert(Share_Data::isContained());

    for (auto& val : Share_Data::some_list)
        std::cout << val << "  ";*/

    MyCopyFile::TestCopy();
    std::cout << "Hello World!\n";
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
