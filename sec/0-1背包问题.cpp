#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 5;
const int MAX_W = 10;
// 问题表示

// 求解结果表示
int dp[MAX_N + 1][MAX_W + 1];
int select[MAX_N + 1];

void Knap(int n, int W, int *w, int *v) // 动态规划法求0/1背包问题
{
    for (int i = 0; i <= n; i++) // 置边界条件dp[i][0]=0
    {
        dp[i][0] = 0;
    }
    for (int r = 0; r <= W; r++) // 置边界条件dp[0][r]=0
    {
        dp[0][r] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int r = 1; r <= W; r++)
        {
            if (r < w[i])
            {
                dp[i][r] = dp[i - 1][r];
            }
            else
            {
                dp[i][r] = max(
                    dp[i - 1][r],
                    dp[i - 1][r - w[i]] + v[i]);
            }
        }
    } // Knap()算法中含有两重for循环, 所以时间复杂度为O(n×W), 空间复杂度为O(n×W)。
}

int Buildx(int n, int W, int *w, int *v) // 回推求最优解
{
    int maxv = 0;
    int i = n, r = W;
    while (i >= 0) // 判断在该取法中，物品i是否要选取
    {
        if (dp[i][r] != dp[i - 1][r])
        {
            select[i] = true; // 选取物品i
            maxv += v[i];     // 累计总价值
            r = r - w[i];
        }
        else
        {
            select[i] = false; //不选取物品i
        }
        i--;
    }
    return maxv;
}

int main()
{
    int n = 5, W = 10;                     // 5种物品, 限制重量不超过10
    int w[MAX_N + 1] = {0, 2, 2, 6, 5, 4}; // 下标0不用
    int v[MAX_N + 1] = {0, 6, 3, 5, 4, 6}; // 下标0不用

    Knap(n, W, w, v);
    int maxv = Buildx(n, W, w, v); // 存放最优解的总价值

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", select[i]);
    }
    printf("\n%d\n", maxv);
    return 0;
}