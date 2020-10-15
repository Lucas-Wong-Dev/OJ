// 角谷定理（递归解法）
/*
角谷定理。输入一个自然数，
若为偶数，则把它除以2，
若为奇数，则把它乘以3加1。
经过如此有限次运算后，总可以得到自然数值1。
求经过多少次可得到自然数1。

如：输入22，
输出  22	11	34	17	52	26	13	40	20	10	5	16	8	4	2	1
STEP=16
*/

#include <stdio.h>
int count = 1; //用于记录运算次数
void f(int n)
{
    if (n == 1)
    {
        printf("%d", n);
    }
    else if (n % 2 == 0)
    {
        printf("%d ", n);
        f(n / 2);
        count++;
    }
    else
    {
        printf("%d ", n);
        f(3 * n + 1);
        count++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    f(n);
    printf("\n");
    printf("%d\n", count);
    return 0;
}