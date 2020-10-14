// 质因数2
// AC
/*
将一个正整数N(1<N<32768)分解质因数，把质因数按从小到大的顺序输出。最后输出质因数的个数。

输入格式
一行，一个正整数
输出格式
两行，第一行为用空格分开的质因数
第二行为质因数的个数

样例输入
66
样例输出
2 3 11
3

样例输入
90
样例输出
2 3 3 5
4

样例输入
37
样例输出
37
1
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
    int N;
    scanf("%d", &N);

    int cnt = 0;
    int primeFactor = getPrimeFactor(N);
    int r = N / primeFactor;
    cnt++;
    printf("%d ", primeFactor);

    while (r > 1)
    {
        primeFactor = getPrimeFactor(r);
        r = r / primeFactor;
        cnt++;
        printf("%d ", primeFactor);
    }

    printf("\n%d\n", cnt);

    return 0;
}