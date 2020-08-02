// 16进制转8进制
/*
输入：16A 
输出：552
*/
// #include <stdio.h>
// const int N = 50;
// long long fact(long long n) // 将十进制数转换为八进制数
// {
//     if (n < 8)
//         return n;
//     else
//         return (fact(n / 8) * 10 + n % 8);
// }
// long long fun(char *s) // 将十六进制数转换为十进制数
// {
//     int t;
//     long long sum = 0;
//     for (int i = 0; s[i]; i++)
//     {
//         if (s[i] >= '0' && s[i] <= '9')
//             t = s[i] - '0';
//         if (s[i] >= 'a' && s[i] <= 'z')
//             t = s[i] - 'a' + 10;
//         if (s[i] >= 'A' && s[i] <= 'Z')
//             t = s[i] - 'A' + 10;
//         sum = sum * 16 + t;
//     }
//     return fact(sum);
// }
// int main()
// {
//     char s[N];
//     scanf("%s", s);
//     printf("%lld", fun(s));
//     return 0;
// }

// 问题描述
// 程序提示用户输入三个字符，每个字符取值范围是0-9，A-F。然后程序会把这三个字符转化为相应的  十六进制整数，并分别以十六进制，十进制，八进制输出。
// 输入格式：输入只有一行，即三个字符。
// 输出格式：输出只有一行，包括三个整数，中间用空格隔开。
// 样例输入
// FFF
// 样例输出
// FFF 4095 7777

#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    string s(3, '0'), ans8;
    char c1, c2, c3;
    scanf("%c %c %c", &c1, &c2, &c3);
    s[0] = c1;
    s[1] = c2;
    s[2] = c3;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            n = n * 16 + s[i] - '0';
        else
            n = n * 16 + s[i] - 'A' + 10;
    }
    if (s[0] == '0')
        s = s.substr(1, s.length() - 1);
    if (s[0] == '0')
        s = s.substr(1, s.length() - 1);
    cout << s << " " << n << " ";
    while (n)
    {
        ans8 += char(n % 8 + '0');
        n /= 8;
    }
    if (ans8 == "")
        ans8 = "0";
    cout << ans8;
    return 0;
}