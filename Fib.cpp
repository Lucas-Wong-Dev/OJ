#include <stdio.h>

const int MAX = 100;
int dp[MAX + 1]; // 所有元素初始化为0
int count = 1;   // 累计调用的步骤

int Fib(int n)
{
    dp[1] = dp[2] = 1;
    printf("(%d)计算出Fib(1)=1\n", count++);
    printf("(%d)计算出Fib(2)=1\n", count++);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        printf("(%d)计算出Fib(%d)=%d\n", count++, i, dp[i]);
    }
    return dp[n];
}

int main()
{
    int ans = Fib(5);
    printf("%d\n", ans);
    return 0;
}
/*
(1)计算出Fib(1)=1
(2)计算出Fib(2)=1
(3)计算出Fib(3)=2
(4)计算出Fib(4)=3
(5)计算出Fib(5)=5
5
*/