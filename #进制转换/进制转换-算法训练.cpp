// 进制转换-算法训练
// AC
// http://lx.lanqiao.cn/problem.page?gpid=T217
/* 
问题描述
编写一个程序，输入一个二进制的字符串（长度不超过32），然后计算出相应的十进制整数，并把它打印出来。

输入格式：输入为一个字符串，每个字符都是’0’或’1’，字符串的长度不超过32。
输出格式：输出一个整数。

样例输入
1101
样例输出
13
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
const int MAX_LEN = 32;
int main()
{
    int ans = 0;
    char input[MAX_LEN + 1];
    scanf("%s", input);
    int len = strlen(input);
    int power = len - 1;

    // 1101
    // len == 4
    // a[0] a[1] a[2] a[3]
    for (int i = 0; i < len; i++)
    {
        if (input[i] == '1')
            ans += pow(2, power);
        power--;
    }

    printf("%d\n", ans);
    return 0;
}