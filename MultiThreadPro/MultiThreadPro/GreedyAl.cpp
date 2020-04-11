#include "GreedyAl.h"

void solve()
{
    int begin = 0;
    int end = N - 1;

    while (begin <= end)
    {
        bool isLeft = false;

        // 用一个i作为哨兵控制S移动字符的能力
        for (int i = 0; begin + i <= end; i++)
        {
            if (S[begin + i] < S[end - i])
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
            std::cout << S[begin++] << std::endl;
        }
        else
        {
            std::cout << S[end--] << std::endl;
        }
    }

    std::cout << std::endl;
}