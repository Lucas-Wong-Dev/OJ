// 矩阵乘法
// AC
// http://lx.lanqiao.cn/problem.page?gpid=T58
/*
问题描述
给定一个N阶矩阵A，输出A的M次幂（M是非负整数） 例如：
A= 
1 2
3 4
A的2次幂=
7 10
15 22

输入格式
第一行是一个正整数N、M（1<=N<=30, 0<=M<=5），表示矩阵A的阶数和要求的幂数
接下来N行，每行N个绝对值不超过10的非负整数，描述矩阵A的值

输出格式
输出共N行，每行N个整数，表示A的M次幂所对应的矩阵。相邻的数之间用一个空格隔开

样例输入
2 2
1 2
3 4
样例输出
7 10
15 22
*/
// 注意：“M是非负整数”，这意味着M也可能是0！矩阵的零次幂等于单位矩阵
#include <stdio.h> // AC
const int MAX_N = 30;
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    long long A[MAX_N + 1][MAX_N + 1] = {0}, ans[MAX_N + 1][MAX_N + 1] = {0}, temp[MAX_N + 1][MAX_N + 1] = {0};

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%lld", &A[i][j]);

    for (int i = 1; i <= N; i++)
        ans[i][i] = 1;

    for (int m = 1; m <= M; m++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                temp[i][j] = 0;
                for (int k = 1; k <= N; k++) // 这个for循环是核心代码
                {
                    // temp[i][j] += A[i][k] * ans[k][j]; // AC
                    temp[i][j] += ans[i][k] * A[k][j]; // AC
                }
                // 可见，在计算一个矩阵的M次幂时，从左向右做矩阵乘法 和 从右向左做矩阵乘法 得到的结果是一样的
            }
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                ans[i][j] = temp[i][j];
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            printf("%lld ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
