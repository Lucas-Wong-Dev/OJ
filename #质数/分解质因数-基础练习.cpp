// 分解质因数-基础练习
// AC
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
#include <iostream> // AC
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    else if (n == 2 || n == 3)
        return true;
    else
    {
        int t = (int)sqrt(n);
        for (int i = 2; i <= t; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true; // ★
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        int cur = i;
        cout << i << "=";
        bool needToPrintTimesSign = false;
        while (cur != 1)
        {
            for (int j = 2; j <= cur; j++)
            {
                if (isPrime(j) && cur % j == 0)
                {
                    cur = cur / j;
                    if (needToPrintTimesSign == true)
                        cout << "*";
                    cout << j;
                    needToPrintTimesSign = true;
                    break; // 这行代码千万不要省略
                }
            }
        }
        cout << endl;
    } // for
    return 0;
}
// 质数又称素数。一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数叫做质数。否则称为合数。
// 2 3 5 7 11 13 17 19 23 29