// 数字三角形-动态规划（递归形式）
// AC
// http://lx.lanqiao.cn/problem.page?gpid=T312
/*
问题描述
（图３.１－１）示出了一个数字三角形。 请编一个程序计算从顶至底的某处的一条路径，使该路径所经过的数字的总和最大。
* 每一步可沿左斜线向下或右斜线向下走
* 1＜三角形行数<=100
* 三角形中的数字为整数0，1，…99

输入格式
文件中首先读到的是三角形的行数。
接下来描述整个三角形

输出格式
最大总和（整数）

样例输入
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

样例输出
30
*/
#include <stdio.h>
#include <string.h>

const int MAX_N = 100; // 数字三角形的最大行数
int D[MAX_N + 1][MAX_N + 1];
// D[i][j]:其值为第i行第j个结点上的数字。其中，i与j都从1开始算，从上向下行号递增
int maxSum[MAX_N + 1][MAX_N + 1];
// maxSum(i, j):代表从第i行的第j个数字到底边的最佳路径上的数字之和，则本题是求maxSum(1, 1)

// 从某个D[i][j]出发，显然下一步有两种可能：要么朝左走向D[i+1][j]，要么朝左走向DD[i+1][j+1]
// 如果朝D[i+1][j]走，那么得到的maxSum[i][j]就是maxSum[i+1][j] + D[i][j]
// 如果朝D[i+1][j+1]走，那么得到的maxSum[i][j]就是maxSum[i+1][j+1] + D[i][j]
// 所以，选择往哪里走，就看maxSum[i+1][j]和maxSum[i+1][j+1]哪个更大了

int getMaxSum(int N, int i, int j)
{
    // 本函数的返回值：从位于(i, j)的结点开始，到底边的最大和
    if (i == N)
        return D[i][j];

    if (maxSum[i + 1][j] == -1) // 如果“从位于(i, j)的结点开始，到底边的最大和”尚未算过
        maxSum[i + 1][j] = getMaxSum(N, i + 1, j);

    if (maxSum[i + 1][j + 1] == -1)
        maxSum[i + 1][j + 1] = getMaxSum(N, i + 1, j + 1);

    if (maxSum[i + 1][j] > maxSum[i + 1][j + 1])
        return maxSum[i + 1][j] + D[i][j];
    else
        return maxSum[i + 1][j + 1] + D[i][j];
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%d", &D[i][j]);
        }
    }

    memset(maxSum, -1, sizeof(maxSum)); // 将 maxSum 全部置成-1, -1代表：“从位于(i, j)的结点开始，到底边的最大和”尚未算过

    printf("%d", getMaxSum(N, 1, 1));
    return 0;
}

// 子问题：从位于(i, j)的结点开始，到底边路径的最大和
// 这个子问题和两个变量i和j相关，那么一个“状态”就是(i, j)的一组取值，即每个数字的位置就是一个“状态”
// 该“状态”所对应的“值”：是从该位置开始，到底边的最佳路径上的数字之和