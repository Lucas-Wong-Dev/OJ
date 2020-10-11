// 分解质因数-算法提高
// AC
/*
问题描述
给定一个正整数n，尝试对其分解质因数

输入格式
仅一行，一个正整数，表示待分解的质因数

输出格式
仅一行，从小到大依次输出其质因数，相邻的数用空格隔开

样例输入
100
样例输出
2 2 5 5

数据规模和约定
n<=2147483647
*/

#include <stdio.h>
#include <math.h>

bool isPrime(int n)
{
    if (n % 2 == 0)
        return false;

    int t = (int)sqrt(n);
    for (int i = 3; i <= t; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}
int getPrimeFactor(int n)
{
    if (n % 2 == 0)
        return 2;

    int t = (int)sqrt(n);
    for (int i = 3; i <= t; i++)
    {
        if (n % i == 0 && isPrime(i))
        {
            return i;
        }
    }

    return n;
}
int main()
{
    int n;
    scanf("%d", &n);

    int primeFactor = getPrimeFactor(n);
    int r = n / primeFactor;
    printf("%d ", primeFactor);

    while (r > 1)
    {
        primeFactor = getPrimeFactor(r);
        r = r / primeFactor;
        printf("%d ", primeFactor);
    }

    return 0;
}