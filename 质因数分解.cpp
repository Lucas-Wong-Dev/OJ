// 质因数分解
/*
问题描述
求出区间[a,b]中所有整数的质因数分解。

输入格式
输入两个整数a，b。

输出格式
每行输出一个数的分解，形如k=a1*a2*a3...(a1<=a2<=a3...，k也是从小到大的)(具体可看样例)

样例输入
3 10
样例输出
3=3
4=2*2
5=5
6=2*3
7=7
8=2*2*2
9=3*3
10=2*5

提示
先筛出所有素数，然后再分解。

数据规模和约定
2<=a<=b<=10000
*/
// #include <stdio.h>
// #include <math.h>
// int getPrimeFactor(int n)
// {
//     int i, j = (int)sqrt(n);
//     if (n % 2 == 0)
//         return 2;
//     for (i = 3; i <= j; i++)
//         if (n % i == 0)
//             return i;
//     return n;
// }
// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     for (int i = a; i <= b; i++)
//     {
//         int primeFactor = getPrimeFactor(i);
//         printf("%d=%d", i, primeFactor);
//         int rest = i / primeFactor;
//         while (rest > 1)
//         {
//             primeFactor = getPrimeFactor(rest);
//             rest /= primeFactor;
//             printf("*%d", primeFactor);
//         }
//         printf("\n");
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
bool isprime(int n)
{
    if (n <= 1)
        return false;
    else if (n == 2 || n == 3)
        return true;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return true;
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        int temp = i;
        cout << i << "=";
        int flag = 0;
        while (temp != 1)
        {
            for (int j = 2; j <= temp; j++)
            {
                if (isprime(j) && temp % j == 0)
                {
                    temp = temp / j;
                    if (flag == 1)
                        cout << "*";
                    cout << j;
                    flag = 1;
                    break; // 这行代码千万不要省略
                }
            }
        }
        cout << endl;
    } // for
    return 0;
}