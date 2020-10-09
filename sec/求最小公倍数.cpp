// 求最小公倍数
// AC
/*
问题描述
从键盘输入M、N（M、N取值长整范围）两个数，求它们的最小公倍数。

输入格式
输入文件只有一行，有两数被空格隔开，分别表示M、N的值。

输出格式
只有一个数，即M、N的最小公倍数。

样例输入
15 20
样例输出
60
*/
// #include <stdio.h> // AC

// long long getGCD(long long a, long long b)
// {
//     long long r = a % b;
//     while (r != 0)
//     {
//         a = b;
//         b = r;
//         r = a % b;
//     }
//     return b;
// }

// int main()
// {
//     long long a, b;
//     scanf("%lld%lld", &a, &b);
//     // printf("%lld %lld\n", a, b);
//     long long gcd = getGCD(a, b);
//     printf("%lld\n", a * b / gcd);
//     return 0;
// }

#include <stdio.h> // AC

long getGCD(long a, long b)
{
    long r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    long a, b;
    scanf("%ld%ld", &a, &b);
    // printf("%ld %ld\n", a, b);
    long gcd = getGCD(a, b);
    printf("%ld\n", a * b / gcd);
    return 0;
}