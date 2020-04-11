#pragma once
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#include <iostream>
#include <initializer_list>

class DP
{
private:
    int Weight;
    int value[10];
    int weight[10];
    int N;
    int res;

public:
    DP(){}

    DP(std::initializer_list<int> list) {
        res = 0;
        int i = 0;
        auto length = list.size() / 2;
        
        //for (int i = 0; i < length; i++)
        //{
        //    weight[i] = list.begin();
        //}

        for (auto itr = list.begin(); itr != list.begin() + length; itr++)
        {
            weight[i++] = *itr;
        }

        i = 0;
        for (auto itr = list.begin() + length; itr != list.end(); itr++)
        {
            value[i++] = *itr;
        }
    }

    bool SetW(int w)
    {
        if(w >= 0)
        {
            Weight = w;
            return true;
        }
 
        return false;
    }

    bool SetN(int n)
    {
        if (n >= 0)
        {
            N = n;
            return true;
        }
        return false;

    }


    int ReturnRes(int i, int restWeight);

    void PrintRes();

};

