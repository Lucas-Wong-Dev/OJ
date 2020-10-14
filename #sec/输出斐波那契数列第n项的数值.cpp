// 输出斐波那契数列第n项的数值
/*
输入：10
输出：55
*/
#include <stdio.h>
int feibo(int n)
{
    if (n <= 2)
        return 1;
    else
        return feibo(n - 1) + feibo(n - 2);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", feibo(n));
    return 0;
}
