// 数字三角形-动态规划（递归形式）
// AC
// http://lx.lanqiao.cn/problem.page?gpid=T312
/*
问题描述
（图３.１－１）示出了一个数字三角形。 请编一个程序计算从顶至底的某处的一条路径，使该路径所经过的数字的总和最大。
●每一步可沿左斜线向下或右斜线向下走；
●1＜三角形行数≤100；
●三角形中的数字为整数0，1，…99；
（图３.１－１）
// 见图片

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

const int MAX_n = 100;
int D[MAX_n + 1][MAX_n + 1];
// D(i, j):表示第i行第j个数字。其中，i与j都从1开始算，从上向下编行号)
int aMaxSum[MAX_n + 1][MAX_n + 1];
// aMaxSum(i, j):代表从第i行的第j个数字到底边的最佳路径的数字之和，则本题是求aMaxSum(1, 1)

// 从某个D(i, j)出发，显然下一步有两种可能：要么走左分支D(i+1, j)，要么右分支D(i+1, j+1)
// 如果走D(i+1, j)，那么得到的aMaxSum(i, j)就是aMaxSum(i+1, j) + D(i, j)
// 如果走D(i+1, j+1)，那么得到的aMaxSum(i, j)就是aMaxSum(i+1, j+1) + D(i, j)
// 所以，选择往哪里走，就看aMaxSum(i+1, j)和aMaxSum(i+1, j+1)哪个更大了

int MaxSum(int N, int i, int j)
{
    if (i == N)
        return D[i][j];

    if (aMaxSum[i + 1][j] == -1) // 如果MaxSum(N, r+1, j)没有计算过
        aMaxSum[i + 1][j] = MaxSum(N, i + 1, j);

    if (aMaxSum[i + 1][j + 1] == -1)
        aMaxSum[i + 1][j + 1] = MaxSum(N, i + 1, j + 1);

    if (aMaxSum[i + 1][j] > aMaxSum[i + 1][j + 1])
        return aMaxSum[i + 1][j] + D[i][j];
    else
        return aMaxSum[i + 1][j + 1] + D[i][j];
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

    memset(aMaxSum, -1, sizeof(aMaxSum)); // 将 aMaxSum 全部置成-1, 开始时所有的 MaxSum(r, j)都没有算过

    printf("%d", MaxSum(N, 1, 1));
    return 0;
}

// 子问题:“从位于(i, j)数字开始，到底边路径的最大和”
// 这个子问题和两个变量i和j相关，那么一个“状态”就是(i, j)的一组取值，即每个数字的位置就是一个“状态”
// 该“状态”所对应的“值”：是从该位置的数字开始，到底边的最佳路径上的数字之和