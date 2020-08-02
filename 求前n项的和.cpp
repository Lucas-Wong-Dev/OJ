// 求前n项的和1+2+…+n
/*
问题描述
求 1+2+3+...+n 的值。

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
// 答案的大小不在你的语言默认的整型(int)范围内，如果使用整型变量来保存结果，会导致结果错误。
// 如果你使用C++或C语言而且准备使用printf输出结果，则你的格式字符串应该写成%I64d以输出long long类型的整数。
#include <stdio.h>
int main()
{
    long long n, sum;
    scanf("%I64d", &n);
    sum = (n + 1) * n / 2;
    printf("%I64d", sum); // 方便起见，竞赛时用cout输出sum
    return 0;
}

// #include <iostream>
// using namespace std;
// int main()
// {
//     long long n;
//     cin >> n;
//     long long result;
//     result = (1 + n) * n / 2;
//     printf("%I64d", result);
//     return 0;
// }

// 用 %u 打印 unsigned int 类型的变量
// 用 %ld 打印 long 类型的变量

// 对 long 类型
// %lx 表示以十六进制格式打印长整数
// %lo 表示以八进制格式打印长整数
// %lu 表示打印 unsigned long 类型的变量

// 对 short 类型
// %hd 表示以十进制格式打印 short 类型的变量
// %ho 表示以八进制格式打印 short 类型的变量