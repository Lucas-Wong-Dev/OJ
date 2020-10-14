// 动态规划（非递归形式）
// 递归的思想在编程时未必要实现为递归函数
// 从aMaxSum[N-1]这一行元素开始向上逐行递推，就能求得aMaxSum[1][1]的值了
#include <stdio.h> // AC

const int MAX_n = 100;

int main()
{
    int D[MAX_n + 1][MAX_n + 1];
    int aMaxSum[MAX_n + 1][MAX_n + 1];

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%d", &D[i][j]);
        }
    }

    for (int j = 1; j <= N; j++)
    {
        aMaxSum[N][j] = D[N][j];
    }

    for (int i = N; i > 1; i--) // 枚举aMaxSum矩阵的各行
    {
        for (int j = 1; j < i; j++) // 求出aMaxSum矩阵中 第i行的各个元素 的值
        {
            if (aMaxSum[i][j] > aMaxSum[i][j + 1])
                aMaxSum[i - 1][j] = D[i - 1][j] + aMaxSum[i][j];
            else
                aMaxSum[i - 1][j] = D[i - 1][j] + aMaxSum[i][j + 1];
        }
    }

    printf("%d", aMaxSum[1][1]);
    return 0;
}
