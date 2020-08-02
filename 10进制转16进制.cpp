// 10进制转16进制
/*
输入格式
输入包含一个非负整数a，表示要转换的数。0<=a<=2147483647

输出格式
输出这个整数的16进制表示

样例输入
30
样例输出
1E

输入：666
输出：29A
*/
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int n, nTemp, count = 0, j; //count是数组a的下标，j用于控制for循环
//     int ans[100];

//     scanf("%d", &n);

//     if (n == 0)
//         printf("%d", n);
//     while (n != 0)
//     {
//         ans[count] = n % 16;
//         n = n / 16;
//         count++;
//     }
//     for (j = count - 1; j >= 0; j--)
//     {
//         if (ans[j] >= 10)
//             printf("%c", (ans[j] - 10 + 'A'));
//         else
//             printf("%c", (ans[j] + '0'));
//             // printf("%d\n", ans[j]);
//     }
//     return 0;
// }

// 另一简单算法
// #include <stdio.h>
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     printf("%X", n); // 注意：样例输出中的字母是大写的，所以这里的X也应当是大写
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int i = 0;
    char ans[100];
    if (a == 0)
    {
        cout << "0";
    }
    else
    {
        while (a != 0)
        {
            if (a % 16 >= 10)
                ans[i++] = a % 16 + 'A' - 10;
            else
                ans[i++] = a % 16 + '0';
            a = a / 16;
        }
    }
    for (int j = i - 1; j >= 0; j--)
        cout << ans[j];
    return 0;
}