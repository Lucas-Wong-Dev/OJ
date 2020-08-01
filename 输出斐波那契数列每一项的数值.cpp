// 输出斐波那契数列每一项的数值
/*
输入：
Enter n:10
输出：
1	1	2	3	5	8	13	21	34	55
*/
#include <stdio.h>
int feibo(int n)
{
    if (n == 2 || n == 1)
        return 1;
    else
        return feibo(n - 1) + feibo(n - 2);
}
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) // 注意这里的循环变量是从1开始循环，别写成0了
    {
        printf("%d\t", feibo(i));
    }
    return 0;
}