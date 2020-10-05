// 矩阵乘法
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
// 分析：竟然有一个0次幂！矩阵的零次幂要输出单位矩阵！

// #include <stdio.h> // AC
// int main()
// {
//     int N, M;
//     scanf("%d%d", &N, &M);

//     long long A[30][30], ans[30][30] = {0}, temp[30][30];
//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < N; j++)
//             scanf("%lld", &A[i][j]);

//     for (int i = 0; i < N; i++)
//         ans[i][i] = 1;

//     for (int m = 0; m < M; m++)
//     {
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 temp[i][j] = 0;
//                 for (int k = 0; k < N; k++)
//                     temp[i][j] += A[i][k] * ans[k][j]; // 核心代码
//             }
//         }
//         for (int i = 0; i < N; i++)
//             for (int j = 0; j < N; j++)
//                 ans[i][j] = temp[i][j];
//     }

//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//             printf("%d ", ans[i][j]);
//         printf("\n");
//     }

//     return 0;
// }

#include <iostream> // AC
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    long long int A[30][30];
    long long int ans[30][30];
    long long int temp[30][30];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++)
        ans[i][i] = 1;

    if (M == 0)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    cout << 1 << " "; // 在输出中，每行末尾是可以多输出一个空格的
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
        return 0;
    }

    while (M != 0)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                temp[i][j] = 0;
                for (int k = 0; k < N; k++)
                {
                    temp[i][j] += ans[i][k] * A[k][j]; // AC
                    // temp[i][j] += A[i][k] * ans[k][j]; // AC
                    // 可见，在计算一个矩阵的M次幂时，从左向右做矩阵乘法 和 从右向左做矩阵乘法 得到的结果是一样的
                }
            }
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans[i][j] = temp[i][j];
        M--;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}