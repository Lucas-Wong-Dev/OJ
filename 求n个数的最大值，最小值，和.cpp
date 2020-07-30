// 求n个数的最大值，最小值，和
/*
输入格式
第一行为整数n，表示数的个数。
第二行有n个数，为给定的n个数，每个数的绝对值都小于10000。
如输入：
Enter n:5
-1 5 9 32 2
输出
max=32
min=-1
sum=47
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(void)
{
    int n, min = INT_MAX, max = INT_MIN;
    int sum = 0; 
    printf("Enter n:");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
        sum += a[i];
    }
    printf("max=%d\n", max);
    printf("min=%d\n", min);
    printf("sum=%d\n", sum);
    return 0;
}