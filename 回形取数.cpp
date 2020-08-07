// 回形取数
/*
问题描述
回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转 90 度。(可见取数的方向是逆时针)
一开始位于矩阵左上角，方向向下。

输入格式
输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。
接下来 m行每行n个整数，表示这个矩阵。

输出格式
输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。
数之间用一个空格分隔，行末不要有多余的空格。

样例输入
3 3
1 2 3
4 5 6
7 8 9
样例输出
1 4 7 8 9 6 3 2 5

样例输入
3 2
1 2
3 4
5 6
样例输出
1 3 5 6 4 2
*/
// #include <stdio.h>
// int main()
// {
//     int m, n;
//     int a[200][200];

//     scanf("%d%d", &m, &n); // 正整数m、n，表示矩阵的行和列
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             scanf("%d", &a[i][j]);

//     for (int i = 0; i < (n + 1) / 2 && i < (m + 1) / 2; i++)
//     {
//         int j;
//         for (j = i; j < m - i; j++) // 向下取数
//             printf("%d ", a[j][i]);
//         for (j = i + 1; j < n - i; j++) // 向右取数
//             printf("%d ", a[m - i - 1][j]);
//         if (n - i - 1 > i) // 向上取数
//             for (j = m - i - 2; j >= i; j--)
//                 printf("%d ", a[j][n - i - 1]);
//         if (m - i - 1 > i) // 向左取数
//             for (j = n - i - 2; j > i; j--)
//                 printf("%d ", a[i][j]);
//     }
//     return 0;
// }

#include <iostream>
#include <memory.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int a[201][201];
    memset(a, -1, sizeof(a));
    int i = 0, j = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    i = 0, j = 0;
    int total = 0;
    while (total < m * n) // 正整数m、n，表示矩阵的行和列
    {
        while (i <= m - 1 && a[i][j] != -1) // down
        {
            cout << a[i][j] << " ";
            a[i][j] = -1;
            i++;
            total++;
        }
        i--;
        j++;
        while (j <= n - 1 && a[i][j] != -1) // right
        {
            cout << a[i][j] << " ";
            a[i][j] = -1;
            j++;
            total++;
        }
        j--;
        i--;
        while (i >= 0 && a[i][j] != -1) // up
        {
            cout << a[i][j] << " ";
            a[i][j] = -1;
            i--;
            total++;
        }
        i++;
        j--;
        while (j >= 0 && a[i][j] != -1) //left
        {
            cout << a[i][j] << " ";
            a[i][j] = -1;
            j--;
            total++;
        }
        j++;
        i++;
    }
    return 0;
}
