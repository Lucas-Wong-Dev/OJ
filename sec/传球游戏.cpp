// 传球游戏
/*
问题描述
上体育课的时候，小蛮的老师经常带着同学们一起做游戏。这次，老师带着同学们一起做传球游戏。
游戏规则是这样的：n个同学站成一个圆圈，其中的一个同学手里拿着一个球，当老师吹哨子时开始传球，每个同学可以把球传给自己左右的两个同学中的一个（左右任意），当老师再次吹哨子时，传球停止，此时，拿着球没传出去的那个同学就是败者，要给大家表演一个节目。
聪明的小蛮提出一个有趣的问题：有多少种不同的传球方法可以使得从小蛮手里开始传的球，传了m次以后，又回到小蛮手里。两种传球的方法被视作不同的方法，当且仅当这两种方法中，接到球的同学按接球顺序组成的序列是不同的。比如有3个同学1号、2号、3号，并假设小蛮为1号，球传了3次回到小蛮手里的方式有1->2->3->1和1->3->2->1，共2种。

输入格式
共一行，有两个用空格隔开的整数n，m（3<=n<=30，1<=m<=30）。
输出格式
共一行，有一个整数，表示符合题意的方法数。

样例输入
3 3
样例输出
2

数据规模和约定
40%的数据满足：3<=n<=30，1<=m<=20
100%的数据满足：3<=n<=30，1<=m<=30
*/
/*
30 30
155117522

10 29
0

3 30
357913942

15 30
155117522
*/
#include <stdio.h>
#include <math.h>
const int MAX_n = 30;
const int MAX_m = 30;
long long sum = 0;

void fun(int curP, int n, int m)
{
    // printf("curP==%d n==%d m==%d\n", curP, n, m);
    if (m == 0)
    {
        if (curP == 1)
        {
            sum++;
        }
        // printf("--> sum==%d m==%d curP=%d\n", sum, m, curP);
        return;
    }

    if (curP - m > 1 && curP + m <= n)
    {
        return;
    }
    else if (curP - m == 1 && curP + m == n + 1)
    {
        sum += 2;
        return;
    }

    if (curP + 1 == n + 1)
    {
        fun(1, n, m - 1);
    }
    else
    {
        fun(curP + 1, n, m - 1);
    }

    if (curP - 1 == 0)
    {
        fun(n, n, m - 1);
    }
    else
    {
        fun(curP - 1, n, m - 1);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    fun(1, n, m);
    // printf("%d\t%d\t%lld\n", n, m, sum);
    printf("%lld\n", sum);

    // int n, m;
    // for (n = 0; n <= MAX_n; n++)
    // {
    //     for (m = 0; m <= MAX_m; m++)
    //     {
    //         fun(1, n, m);
    //         printf("%d\t%d\t%lld\n", n, m, sum);
    //         sum = 0;
    //     }
    // }

    return 0;
}
