// 序列求和
// AC
// http://lx.lanqiao.cn/problem.page?gpid=T2
/*
问题描述
求1+2+3+...+n的值。

输入格式
输入包括一个整数n。

输出格式
输出一行，包括一个整数，表示 1+2+3+...+n 的值。

样例输入
4
样例输出
10
样例输入
100
样例输出
5050

数据规模与约定
1 <= n <= 1,000,000,000。
*/
/* 
来自oj的友情提醒 ★

答案的大小不在你的语言默认的整型(int)范围内，如果使用整型变量来保存结果，会导致结果错误。
如果你使用C++或C语言而且准备使用printf输出结果，则你的格式字符串应该写成%I64d以输出long long类型的整数。 
*/

// #include <stdio.h>
// int main()
// {
//     long long n, sum;

//     // scanf("%I64d", &n); // AC：这种写法在蓝桥练习系统上能通过
//     scanf("%lld", &n); // AC

//     sum = (n + 1) * n / 2;

//     // printf("%I64d", sum); // AC
//     printf("%lld", sum); // AC

//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;

    long long sum;
    sum = (1 + n) * n / 2;

    // printf("%I64d", sum); // AC
    // printf("%lld", sum); // AC
    cout << sum; // AC

    return 0;
}

// 对 long 类型的变量
// %ld 表示打印 long 类型的变量
// %lx 表示以十六进制格式打印 long 类型的变量
// %lo 表示以八进制格式打印 long 类型的变量

// %lu 表示打印 unsigned long 类型的变量
// %u  表示打印 unsigned int 类型的变量

// 对 short 类型的变量
// %hd 表示以十进制格式打印 short 类型的变量
// %ho 表示以八进制格式打印 short 类型的变量