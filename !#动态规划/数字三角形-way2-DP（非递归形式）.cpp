// 动态规划（非递归形式）
// 递归的思想在编程时未必要实现为递归函数
// 从maxSum[N-1]这一行元素开始向上逐行递推，就能求得maxSum[1][1]的值了
#include <stdio.h> // AC

const int MAX_N = 100;

int main()
{
    int D[MAX_N + 1][MAX_N + 1];
    int maxSum[MAX_N + 1][MAX_N + 1];

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
        maxSum[N][j] = D[N][j];
    }

    for (int i = N; i > 1; i--) // 遍历maxSum矩阵的各行
    {
        for (int j = 1; j <= i - 1; j++) // 求出maxSum矩阵中 第i行的各个元素 的值
        // 注意：这里j取1 ~ i-1
        // 当i取N时，j取1 ~ N-1
        {
            if (maxSum[i][j] > maxSum[i][j + 1])
            {
                maxSum[i - 1][j] = maxSum[i][j] + D[i - 1][j];
            }
            else
            {
                maxSum[i - 1][j] = maxSum[i][j + 1] + D[i - 1][j];
            }
        }
    }

    // printf("-------------\n");
    // for (int i = 0; i <= N; i++)
    // {
    //     for (int j = 0; j <= N; j++)
    //     {
    //         printf("%d\t", maxSum[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("-------------\n");

    printf("%d", maxSum[1][1]);
    return 0;
}
