// 回文数
// AC
/*
问题描述
1221 是一个非常特殊的数，它从左边读和从右边读是一样的，编程求所有这样的四位十进制数。

输出格式
按从小到大的顺序输出满足条件的四位十进制数。
*/

#include <stdio.h> // AC
int main()
{
    int a, b, c, d;
    for (int i = 1000; i <= 9999; i++)
    {
        a = i / 1000;         // 千位
        b = (i % 1000) / 100; // 百位
        c = (i % 100) / 10;   // 十位
        d = i % 10;           // 个位
        if (a == d && b == c)
            printf("%d%d%d%d\n", a, b, c, d);
    }
    return 0;
}

// #include <iostream> // AC
// using namespace std;
// int main()
// {
//     for (int i = 1; i <= 9; i++)
//     {
//         for (int j = 0; j <= 9; j++)
//         {
//             cout << i << j << j << i << endl;
//         }
//     } // 可见我们可以一个数位一个数位地输出一个数字
//     return 0;
// }
