// 质因数
// AC
/*
将一个正整数N(1<N<32768)分解质因数。例如，输入90，打印出90=2*3*3*5。

样例输入
66
样例输出
66=2*3*11
*/
// 分解质因数，又称分解质因子、分解素因数
// 每个合数都可以写成几个质数相乘的形式，其中每个质数都是这个合数的因数，把一个合数用质因数相乘的形式表示出来，叫做分解质因数。如30=2×3×5。
// 分解质因数只针对合数。
#include <stdio.h> // AC
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
    {
        return 2;
    }

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

    int primeFactor = getPrimeFactor(N);
    printf("%d=%d", N, primeFactor);
    int r = N / primeFactor;

    while (r > 1)
    {
        primeFactor = getPrimeFactor(r);
        printf("*%d", primeFactor);
        r = r / primeFactor;
    }

    return 0;
}