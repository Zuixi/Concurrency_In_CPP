#include "GreedyAl.h"

void solve()
{
    int begin = 0;
    int end = N - 1;

    while (begin <= end)
    {
        bool isLeft = false;

        // ��һ��i��Ϊ�ڱ�����S�ƶ��ַ�������
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