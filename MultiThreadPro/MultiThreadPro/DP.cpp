#include "DP.h"
#include <cmath>

int DP::ReturnRes(int i, int restWeight)
{
    // ����Ѿ������һ������
    if (i == N)
    {
        res = 0;
    }
    // �����ǰ�����������ڱ���ʣ���������������ѡ��һ��
    else if (weight[i] > restWeight)
    {
        res = ReturnRes(i + 1, restWeight);
    }
    else
        res = std::max(ReturnRes(i + 1, restWeight), ReturnRes(i + 1, restWeight - weight[i]) + value[i]);

    return res;
}

void DP::PrintRes()
{
    std::cout << "max res = " << res << std::endl;
}