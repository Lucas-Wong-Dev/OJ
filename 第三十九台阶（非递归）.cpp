// 第三十九台阶（非递归）
#include <stdio.h>
long long fact(int m, int n)
{
    long long a = 1, b = 1, c = 1; //因为阶乘数m，n 稍大，阶乘结果变大
    for (int i = m + n; i >= 1; i--) //求m+n的阶乘
        a = a * i;
    for (int i = m; i >= 1; i--) //求m的阶乘
        b = b * i;
    for (int i = n; i >= 1; i--) //求n的阶乘
        c = c * i;
    return a / (b * c);
}
int main()
{
    long long sum = 0;
    for (int i = 1; i <= 37; i++)
        for (int j = 1; j <= 19; j++)
        {
            if ((i + j) % 2 == 0 && (i + 2 * j) == 39) //满足两只脚的走的总的步数为偶数且走的阶梯数总和为 39
            {
                sum += fact(i, j);
            }
        }
    printf("%lld\n", sum);
    return 0;
}