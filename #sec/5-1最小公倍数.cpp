// 5-1最小公倍数
// AC
/*
问题描述
编写一函数lcm，求两个正整数的最小公倍数。

样例输入
3 5
样例输出

数据规模和约定
两个数都小于65536。
*/
#include <stdio.h>

int getGCD(int a, int b)
{
    int r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int getLCM(int a, int b)
{
    return a * b / getGCD(a, b);
}
int main()
{
    // (2**32-1)-(2**16-1)*(2**16-1)==131070，所以int类型的变量（占4字节时）是完全能够对付这题的
    int a, b;
    scanf("%d%d", &a, &b);
    int lcm = getLCM(a, b);
    printf("%d\n", lcm);
    return 0;
}