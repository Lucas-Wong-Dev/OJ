// 矩阵乘法
/*
问题描述
给定一个N阶矩阵A，输出A的M次幂（M 是非负整数） 例如：
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
// 分析：竟然有一个0次幂！矩阵的零次幂要输出单位矩阵！

// #include <stdio.h>
// int main()
// {
//     int a[30][30], b[30][30] = {0}, temp[30][30];
//     int M, N;
//     scanf("%d%d", &N, &M);

//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < N; j++)
//             scanf("%d", &a[i][j]);

//     for (int i = 0; i < N; i++)
//         b[i][i] = 1;

//     for (int m = 0; m < M; m++)
//     {
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 temp[i][j] = 0;
//                 for (int k = 0; k < N; k++)
//                     temp[i][j] += a[i][k] * b[k][j]; // 核心代码
//             }
//         }
//         for (int i = 0; i < N; i++)
//             for (int j = 0; j < N; j++)
//                 b[i][j] = temp[i][j];
//     }

//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//             printf("%d ", b[i][j]);
//         printf("\n");
//     }

//     return 0;
// }

#include <iostream>
using namespace std;
long long int b[40][40];
int main()
{
    int n, m;
    cin >> n >> m;
    long long int a[40][40];
    long long int t[40][40];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            t[i][j] = a[i][j];
        }
    }

    if (m == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    cout << 0 << " ";
                }
                else
                {
                    cout << 1 << " ";
                }
            }
            cout << endl;
        }
        return 0;
    }

    while (--m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int k = n;
                while (k)
                {
                    b[i][j] += t[i][k - 1] * a[k - 1][j];
                    k--;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                t[i][j] = b[i][j];
                b[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}