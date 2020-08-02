// // 判断是否是回文
// #include <stdio.h>
// const int N = 60;
// int main()
// {
//     char a[N];
//     scanf("%s", a);
//     int len = 0;
//     for (int i = 0; i < N; i++)
//     {
//         printf("%c", a[i]);
//         if (a[i] != '\0') // 如果当前字符不是'\0'，则len加1
//             len++;
//         else // 如果当前字符是'\0'，则退出计数。这个else切记不能省略！
//             break;
//     }
//     printf("\nlen: %d\n", len);
//     bool isH = true;
//     for (int i = 0; i < len / 2; i++)
//     {
//         if (a[i] != a[len - i - 1])
//         {
//             isH = false;
//             break;
//         }
//     }
//     if (isH)
//         printf("is\n");
//     else
//         printf("is not\n");

//     return 0;
// }

// 编程判断一个字符串是否是回文，当字符串是回文时，输出字符串：yes!，否则输出字符串：no!。
// 所谓回文即正向与反向的拼写都一样，如adgda。长度在100以内，且全为小写字母
// 样例输入adgda
// 样例输出yes!

#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int i = 0, j = s.length() - 1;
    while (i < j) // 如果不是使用字符数组来存放输入的字符串，而是使用string类型的变量来存放，那么用这种双指针的方式来进行判断是非常便捷的
    {
        if (s[i] != s[j])
        {
            cout << "no!";
            return 0;
        }
        i++;
        j--;
    }
    cout << "yes!";
    return 0;
}