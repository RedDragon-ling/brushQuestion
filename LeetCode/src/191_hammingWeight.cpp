/********************************************************************************************
 * @author reddragon
 * @date 2021/3/22
 * @brief 1的个数
 * 1. 循环检查
 * 我们可以循环检查给定整数二进制的每一位是否为1
 * 时间复杂度: O(K)k最大32         空间复杂度: O(1)
 * 
 * 2. 位运算优化
 * 观察这个运算：n & (n - 1)，其运算结果恰为把 n 的二进制位中的最低位的 1 变为 0 之后的结果。
 * 如6 & (6 - 1) = 4, 这样我们可以利用这个位运算的性质加速我们的检查过程，
 * 在实际代码中，我们不断让当前的 n 与 n−1 做与运算，直到 n 变为 0 即可。
 * 因为每次运算会使得 n 的最低位的 1 被翻转，因此运算次数就等于 n 的二进制位中 1 的个数。
 * 时间复杂度: O(logN)              空间复杂度: O(1)
*********************************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 二进制优化, 循环1的次数
int hammingWeight(uint32_t n)
{
    int ans = 0;
    while (n)
    {
        n &= n - 1;
        ++ans;
    }
    return ans;
}

// 循环检测, 最多32次
int hammingWeight(uint32_t n)
{
    int ans = 0;
    while (n)
    {
        if (n & 1)
            ++ans;
        n >>= 1;
    }
    return ans;
}

int main()
{
    cout << hammingWeight(6) << endl;
    return 0;
}
