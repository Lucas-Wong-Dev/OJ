// 16进制转10进制
/*
输入：14B 
输出：331
*/

// #include <stdio.h>
// #define N 50
// long long fun(const char *s)
// {
//     long long sum = 0;
//     for (int i = 0; s[i]; i++)
//     {
//         if (s[i] >= '0' && s[i] <= '9')
//             sum = sum * 16 + s[i] - '0';
//         if (s[i] >= 'a' && s[i] <= 'z')
//             sum = sum * 16 + s[i] - 'a' + 10;
//         if (s[i] >= 'A' && s[i] <= 'Z')
//             sum = sum * 16 + s[i] - 'A' + 10;
//     }
//     return sum;
// }
// int main()
// {
//     char s[N]; // 定义一个数组来保存输入的16进制数，这个16进制数以字符串的方式输入
//     scanf("%s", s);
//     long long m = fun(s);
//     printf("%lld", m);
//     return 0;
// }

// 十六进制转十进制
// 问题描述
// 从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出。
// 注：十六进制数中的10~15分别用大写的英文字母A、B、C、D、E、F表示。
// 样例输入
// FFFF
// 样例输出
// 65535

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        int len = s.length();
        long long sum = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'F')
            {
                sum = sum * 16 + s[i] - 'A' + 10;
            }
            else
            {
                sum = sum * 16 + s[i] - '0';
            }
        }
        cout << sum << endl;
    }
    return 0;
}
