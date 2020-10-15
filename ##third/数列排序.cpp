// 数列排序
// AC
// http://lx.lanqiao.cn/problem.page?gpid=T52
/*
问题描述
给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200

输入格式
第一行为一个整数n。
第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。

输出格式
输出一行，按从小到大的顺序输出排序后的数列。

样例输入
5
8 3 6 4 9
样例输出
3 4 6 8 9
*/
// #include <stdio.h> // AC 选择排序
// const int MAX_n = 200;
// int a[MAX_n + 1] = {0};
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++)
//     {
//         scanf("%d", &a[i]);
//     }

//     for (int i = 1; i <= n - 1; i++)
//     {
//         int k = i;
//         for (int j = i + 1; j <= n; j++)
//         {
//             if (a[j] < a[k])
//             {
//                 k = j;
//             }
//         }
//         if (k != i)
//         {
//             int t = a[i];
//             a[i] = a[k];
//             a[k] = t;
//         }
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         printf("%d ", a[i]);
//     }

//     return 0;
// }

#include <stdio.h> // AC 冒泡排序
const int MAX_n = 200;
int a[MAX_n + 1] = {0};
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] < a[i])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}