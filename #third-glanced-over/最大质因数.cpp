// 最大质因数
// AC
/*
问题描述
给出N个数字，求出有最大的最大质因数的那个数

输入格式
第一行：一个整数N。
接下来的N行，每行一个整数A_i，表示给出的那N个数字。

输出格式
第一行：一个整数，拥有最大的最大质因数的那个数。

样例输入
4
36
38
40
42
样例输出
38

数据规模和约定
60%的数据满足：N<=100
100%的数据满足：N<=2500,A_i<=20000
*/
#include <stdio.h>
#include <math.h>
const int MAX_N = 2500;

bool isPrime(int n) // ★
{
    if (n % 2 == 0)
        return false;

    int t = sqrt(n);
    for (int i = 3; i <= t; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int A[MAX_N];
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int index = 0;
    int maxPrimeFactor = -1;
    for (int i = 0; i < N; i++)
    {
        int maxPrimeFactorOfCurNum = -1;
        for (int j = A[i]; j >= 2; j--)
        {
            if (A[i] % j == 0 && isPrime(j))
            {
                maxPrimeFactorOfCurNum = j;
                break;
            }
        }
        if (maxPrimeFactorOfCurNum > maxPrimeFactor)
        {
            maxPrimeFactor = maxPrimeFactorOfCurNum;
            index = i;
        }
    }
    printf("%d\n", A[index]);
    return 0;
}