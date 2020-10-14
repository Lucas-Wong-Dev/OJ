#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100;
const int MAX_W = 10000;
int dp[MAX_N + 1][MAX_W + 1];
int select[MAX_N + 1]; // 解向量
// 这个解向量描述了最优解（最优解是能使放入背包的物品的总价值最大的放置方案）
// 解向量从下标为1的数组元素开始使用

void Knap(int N, int W, int *w, int *v) // 动态规划法求解0-1背包问题
{
    for (int i = 0; i <= N; i++) // 包的最大载重量为0，不能装入任何物品，此时最优解下的总价值为0
    {
        dp[i][0] = 0;
    }
    for (int r = 0; r <= W; r++) // 没有任何物品可装入，此时最优解下的总价值为0
    {
        dp[0][r] = 0;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int r = 1; r <= W; r++) // r是包的剩余载重量
        {
            if (r < w[i]) // 当 背包剩余载重量r<物品i的重量w[i] 时，物品i放不下
            {
                dp[i][r] = dp[i - 1][r];
            }
            else // 当 背包剩余载重量r>=物品i的重量w[i] 时。在 不放入 和 放入 物品i之间选最优解
            {
                dp[i][r] = max(
                    dp[i - 1][r],
                    dp[i - 1][r - w[i]] + v[i]);
            }
        }
    } // Knap()算法中含有两重for循环, 所以时间复杂度为O(N×W), 空间复杂度为O(N×W)
}

int Buildx(int N, int W, int *w, int *v, int *totalWeightOfLoadedObjects) // 推导出最优解对应的解向量x
{
    int maxv = 0;     // 在最优解（能使放入背包的物品的总价值最大的放置方案）下，最终放入背包的物品的总价值
    int i = N, r = W; // r是包的剩余载重量
    while (i >= 1)    // 判断在该放置方案中，物品i是否要被放入包中
    {
        if (dp[i][r] != dp[i - 1][r])
        {                     // 表示放入物品i
            select[i] = true; // 选取物品i
            maxv += v[i];     // 因为在该放置方案中，物品i需要被放入包，所以累计总价值要加上物品i的价值
            r = r - w[i];     // 因为在该放置方案中，物品i需要被放入包，所以包的剩余载重量要减去物品i的重量
        }
        else // 表示物品i放不下或者不放入物品i
        {
            select[i] = false; // 不选取物品i
        }
        i--;
    }
    *totalWeightOfLoadedObjects = W - r;
    return maxv;
}

int main()
{
    int N = 5, W = 10;
    // 共有N件物品，包的最大载重量为W
    // 求解：放入哪些物品能使得总价值最高
    int w[MAX_N + 1] = {0, 2, 2, 6, 5, 4}; // 物品i的重量。下标0不用
    int v[MAX_N + 1] = {0, 6, 3, 5, 4, 6}; // 物品i的价值。下标0不用

    int totalWeightOfLoadedObjects = 0;
    Knap(N, W, w, v);
    int maxv = Buildx(N, W, w, v, &totalWeightOfLoadedObjects); // 在最优解（能使放入背包的物品的总价值最大的放置方案）下，最终放入背包的物品的总价值

    for (int i = 1; i <= N; i++)
    {
        printf("%d ", select[i]);
    }
    printf("\n%d %d\n", maxv, totalWeightOfLoadedObjects);
    // printf("\n%d\n", dp[N][W]);
    // --------------------------------------------
    // bool equal = true;
    // for (int n1 = 0; n1 <= N; n1++)
    // {
    //     for (int w1 = 0; w1 <= W; w1++)
    //     {
    //         Knap(n1, w1, w, v);
    //         int maxv = Buildx(n1, w1, w, v);
    //         printf("%d %d ", maxv, dp[n1][w1]);
    //         if (maxv == dp[n1][w1])
    //         {
    //             printf("%s\n", "equal");
    //         }
    //         else
    //         {
    //             printf("%s\n", "not equal");
    //             equal = false;
    //             break;
    //         }
    //     }
    //     if (equal == false)
    //     {
    //         break;
    //     }
    // }
    // if (equal == false)
    // {
    //     printf("%s\n", "fail!");
    // }
    // else
    // {
    //     printf("%s\n", "succeed!");
    // }

    return 0;
}