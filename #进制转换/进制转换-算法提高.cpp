// 进制转换-算法提高
// http://lx.lanqiao.cn/problem.page?gpid=T242
// AC
/*
问题描述
程序提示用户输入三个字符，每个字符取值范围是0-9，A-F。然后程序会把这三个字符转化为相应的十六进制整数，并分别以十六进制，十进制，八进制输出。

输入格式：输入只有一行，即三个字符。
输出格式：输出只有一行，包括三个整数，中间用空格隔开。

样例输入
FFF
样例输出
FFF 4095 7777
*/
// hexadecimal adj. 十六进制的 n. 十六进制
#include <stdio.h>
int d2(int d, int t)
{
    if (d < t)
    {
        return d;
    }
    else
    {
        return d2(d / t, t) * 10 + d % t;
    }
}
int main()
{
    char input[3 + 1];
    scanf("%s", input);

    // 使用for循环来将十六进制数转换为十进制数
    int d = 0;
    for (int i = 0; i < 3; i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            d = d * 16 + (input[i] - '0');
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            d = d * 16 + (input[i] - 'A' + 10); // 不要忘了“+ 10”！
        }
    }

    int o = d2(d, 8);

    // 有一个输入是“000”
    // 对应的输出是“0 0 0”
    // 若输入为“000”，再以十六进制数输出这个数时，就应当输出“0”
    char *p = input;
    for (int i = 0; i < (3 - 1); i++)
    {
        if (*p == '0')
        {
            p++;
        }
        else
        {
            break;
        }
    }

    printf("%s %d %d", p, d, o);
    return 0;
}