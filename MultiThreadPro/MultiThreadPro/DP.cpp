#include "DP.h"
#include <cmath>

int DP::ReturnRes(int i, int restWeight)
{
    // 如果已经是最后一个东西
    if (i == N)
    {
        res = 0;
    }
    // 如果当前货物重量大于背包剩余重量，则继续挑选下一个
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