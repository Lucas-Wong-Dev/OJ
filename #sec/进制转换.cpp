// 进制转换
// AC
/*
问题描述
编写函数将十进制整数按8进制输出，然后编写main函数验证该函数。例如输入12，则输出为：12=014，输入32，则输出32=040。

输入格式
输入一个整数。

输出格式
输出这个整数的八进制形式。

样例输入
12
样例输出
014

数据规模和约定
输入的整数n>=0.
*/
// #include <stdio.h>
// int d2b(int n) // 这是一个递归函数，用于将十进制数转换为二进制数
// {
//     if (n < 2) // 将这个函数里的三个2换成8，就可以将本函数改造为十进制转八进制函数
//         return n;
//     else
//     {
//         return d2b(n / 2) * 10 + n % 2;
//     }
// }

// int d2oc(int n) // 这是一个递归函数，用于将十进制数转换为八进制数
// {               // octal adj. 八进制的
//     if (n < 8)
//         return n;
//     else
//     {
//         return d2oc(n / 8) * 10 + n % 8;
//     }
// }

// int d2(int n, int t) // 这是一个递归函数，用于将十进制数转换为n进制数
// {
//     if (n < t)
//         return n;
//     else
//     {
//         return d2(n / t, t) * 10 + n % t;
//     }
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     int ans = d2(n, 8);
//     if (ans == 0) // ★
//     {
//         printf("0\n");
//     }
//     else
//     {
//         printf("0%d\n", ans);
//     }

//     return 0;
// }

// -------------------------------------
// 进制转换
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
// AC
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

    char *p = input;
    for (int i = 0; (i < (3 - 1)) && ((*p) == '0'); i++)
    {
        p++;
    }

    printf("%s %d %d", p, d, o);
    return 0;
}