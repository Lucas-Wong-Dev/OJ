// 十进制转十六进制
// AC
/*
问题描述
十六进制数是在程序设计时经常要使用到的一种整数的表示方式。它有0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F共16个符号，分别表示十进制数的0至15。十六进制的计数方法是满16进1，所以十进制数16在十六进制中是10，而十进制的17在十六进制中是11，以此类推，十进制的30在十六进制中是1E。
给出一个非负整数，将它表示成十六进制的形式。

输入格式
输入包含一个非负整数a，表示要转换的数。0<=a<=2147483647
输出格式
输出这个整数的16进制表示

样例输入
30
样例输出
1E
*/
// 2147483647（十进制）==7FFFFFFF（十六进制）
// #include <stdio.h> // AC
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     printf("%X", n); // 注意：样例输出中的字母是大写的，所以这里的X也应当是大写
//     return 0;
// }

// #include <iostream> // AC
// using namespace std;
// int main()
// {
//     int a;
//     cin >> a;
//     int i = 0;
//     char ans[100];
//     if (a == 0)
//     {
//         cout << "0";
//     }
//     else
//     {
//         while (a != 0)
//         {
//             if (a % 16 >= 10)
//                 ans[i++] = a % 16 + 'A' - 10;
//             else
//                 ans[i++] = a % 16 + '0';
//             a = a / 16;
//         }
//     }
//     for (int j = i - 1; j >= 0; j--)
//         cout << ans[j];
//     return 0;
// }

#include <stdio.h> // AC
#include <stdlib.h>
int main()
{
    int n, index = 0; // index是数组ans的下标
    int ans[100];

    scanf("%d", &n);

    if (n == 0)
        printf("%d", n);
    while (n != 0)
    {
        ans[index] = n % 16;
        n = n / 16;
        index++;
    }
    for (int i = index - 1; i >= 0; i--)
    {
        if (ans[i] >= 10)
            printf("%c", (ans[i] - 10 + 'A'));
        else
            printf("%c", (ans[i] + '0')); // AC
            // printf("%d", ans[i]); // AC
    }
    return 0;
}
