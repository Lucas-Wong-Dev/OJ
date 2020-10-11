// 回形取数
// AC
/*
问题描述
回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。(可见取数的方向是逆时针)
一开始位于矩阵左上角，方向向下。

输入格式
输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。
接下来m行每行n个整数，表示这个矩阵。

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
#include <stdio.h> // AC
const int MAX_m = 200;
const int MAX_n = 200;
int main()
{
    int a[MAX_m + 1][MAX_n + 1];
    int m, n;
    scanf("%d%d", &m, &n); // 正整数m、n，表示矩阵的行和列

    // int cnt = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            // a[i][j] = cnt;
            // cnt++;
        }
    }

    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("------------\n");

    for (int i = 1; i <= (n + 1) / 2 && i <= (m + 1) / 2; i++)
    {
        int j;

        for (j = i; j <= m + 1 - i; j++) // 向下取数
            printf("%d ", a[j][i]);

        for (j = i + 1; j <= n + 1 - i; j++) // 向右取数
            printf("%d ", a[m + 1 - i][j]);

        if (n - i >= i) // 向上取数
            for (j = m - i; j >= i; j--)
                printf("%d ", a[j][n + 1 - i]);

        if (m - i >= i) // 向左取数
            for (j = n - i; j > i; j--)
                printf("%d ", a[i][j]);
    }
    return 0;
}

// #include <iostream> // AC
// #include <cstring>
// #include <climits>
// const int MAX_m = 200;
// const int MAX_n = 200;
// using namespace std;
// int main()
// {
//     int m, n;
//     cin >> m >> n; // 正整数m、n，表示矩阵的行和列
//     int a[MAX_m + 1][MAX_n + 1];
//     memset(a, -1, sizeof(a));

//     int i = 0, j = 0;
//     for (i = 0; i < m; i++)
//         for (j = 0; j < n; j++)
//             cin >> a[i][j];

//     i = 0, j = 0;
//     int numOfRead = 0; // 已读的元素的数量
//     while (numOfRead < m * n)
//     {
//         while (i <= m - 1 && a[i][j] != INT_MIN) // down
//         {
//             cout << a[i][j] << " ";
//             a[i][j] = INT_MIN;
//             i++;
//             numOfRead++;
//         }
//         i--;
//         j++;
//         while (j <= n - 1 && a[i][j] != INT_MIN) // right
//         {
//             cout << a[i][j] << " ";
//             a[i][j] = INT_MIN;
//             j++;
//             numOfRead++;
//         }
//         j--;
//         i--;
//         while (i >= 0 && a[i][j] != INT_MIN) // up
//         {
//             cout << a[i][j] << " ";
//             a[i][j] = INT_MIN;
//             i--;
//             numOfRead++;
//         }
//         i++;
//         j--;
//         while (j >= 0 && a[i][j] != INT_MIN) //left
//         {
//             cout << a[i][j] << " ";
//             a[i][j] = INT_MIN;
//             j--;
//             numOfRead++;
//         }
//         j++;
//         i++;
//     }
//     return 0;
// }
