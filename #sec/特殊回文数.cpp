// 特殊回文数
/*
123321是一个非常特殊的数，它从左边读和从右边读是一样的。
输入一个正整数n，编程求所有这样的五位和六位十进制数，满足各位数字之和等于n。

输入格式
输入一行，包含一个正整数n。

输出格式
按从小到大的顺序输出满足条件的整数，每个整数占一行。

样例输入
52

样例输出
899998
989989
998899

数据规模和约定
1<=n<=54。
*/
#include <stdio.h> // AC
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 10000; i <= 99999; i++)
    {
        int a = i / 10000;
        int b = (i % 10000) / 1000;
        int c = (i % 1000) / 100;
        int d = (i % 100) / 10;
        int e = i % 10;
        if (a == e && b == d && a + b + c + d + e == n)
            printf("%d\n", i);
    }
    for (int i = 100000; i < 999999; i++)
    {
        int a = i / 100000;
        int b = (i % 100000) / 10000;
        int c = (i % 10000) / 1000;
        int d = (i % 1000) / 100;
        int e = (i % 100) / 10;
        int f = i % 10;
        if (a == f && b == e && c == d && a + b + c + d + e + f == n)
            printf("%d\n", i);
    }
    return 0;
}

// #include <iostream> // AC
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i1 = 1; i1 <= 9; i1++)
//         for (int i2 = 0; i2 <= 9; i2++)
//             for (int i3 = 0; i3 <= 9; i3++)
//             {
//                 if ((i1 + i2 + i3 + i2 + i1) == n)
//                     cout << i1 << i2 << i3 << i2 << i1 << endl;
//             }
//     for (int i1 = 1; i1 <= 9; i1++)
//         for (int i2 = 0; i2 <= 9; i2++)
//             for (int i3 = 0; i3 <= 9; i3++)
//             {
//                 if ((i1 + i2 + i3 + i3 + i2 + i1) == n)
//                     cout << i1 << i2 << i3 << i3 << i2 << i1 << endl;
//             }
//     return 0;
// }