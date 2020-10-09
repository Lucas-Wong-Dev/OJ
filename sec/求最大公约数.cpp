// 求最大公约数
// AC
/*
编写一函数gcd，求两个正整数的最大公约数。
样例输入: 
5 15
样例输出:
5
样例输入: 
7 2
样例输出:
1
*/

#include <stdio.h>
// int getGCD(int a, int b) // AC
// {
//     int r = a % b;
//     while (r != 0)
//     {
//         a = b;
//         b = r;
//         r = a % b;
//     }
//     return b;
// }
int getGCD(int a, int b) // AC
{
    int r; // remainder n. 余数
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int gcd = getGCD(a, b);
    printf("%d\n", gcd);
    return 0;
}