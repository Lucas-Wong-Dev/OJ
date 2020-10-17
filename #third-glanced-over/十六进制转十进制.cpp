// 十六进制转十进制
// AC
/*
问题描述
从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出。
注：十六进制数中的10~15分别用大写的英文字母A、B、C、D、E、F表示。

样例输入
FFFF
样例输出
65535
*/
#include <iostream> // AC
using namespace std;
int main()
{
    long long a; // 这里使用long long来存储所输入的数据，以防因输入数据过大而导致的溢出
    // scanf("%x", &a); // AC
    scanf("%X", &a); // AC
    printf("%lld", a);
    return 0;
}

// #include <iostream> // AC
// #include <cstring>
// using namespace std;
// int main()
// {
//     string s;
//     cin >> s;
//     int len = s.length();
//     long long sum = 0;
//     for (int i = 0; i < len; i++)
//     {
//         if (s[i] >= 'A' && s[i] <= 'F')
//         {
//             sum = sum * 16 + s[i] - 'A' + 10;
//         }
//         else
//         {
//             sum = sum * 16 + s[i] - '0';
//         }
//     }
//     cout << sum << endl;

//     return 0;
// }

// #include <stdio.h> // AC
// const int N = 8;
// long long fun(const char *s)
// {
//     long long sum = 0;
//     for (int i = 0; s[i] != '\0'; i++)
//     {
//         if (s[i] >= '0' && s[i] <= '9')
//             sum = sum * 16 + s[i] - '0';
//         else if (s[i] >= 'A' && s[i] <= 'Z')
//             sum = sum * 16 + s[i] - 'A' + 10;
//         else if (s[i] >= 'a' && s[i] <= 'z')
//             sum = sum * 16 + s[i] - 'a' + 10; // 注意：在“if - else if - else”类型的选择语句中，最后的else分支可以省略
//     }
//     return sum;
// }
// int main()
// {
//     char s[N + 1]; // 定义一个数组来保存输入的16进制数，这个16进制数以字符串的方式输入
//     scanf("%s", s);
//     long long ans = fun(s);
//     printf("%lld", ans);
//     return 0;
// }