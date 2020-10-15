// 01字符串
/*
对于⻓度为5位的⼀个01串，每⼀位都可能是0或1，⼀共有32种可能。它们的前⼏个是：
00000
00001
00010
00011
00100
请按从⼩到⼤的顺序输出这32种01串。

输⼊格式
本试题没有输⼊。

输出格式
输出32⾏，按从⼩到⼤的顺序每⾏⼀个⻓度为5的01串。

样例输出
00000
00001
00010
00011
*/
#include <iostream>
using namespace std;
int main()
{
    // int cnt = 0;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++)
                for (int l = 0; l <= 1; l++)
                    for (int m = 0; m <= 1; m++)
                    {
                        cout << i << j << k << l << m << endl;
                        // cnt++;
                    }
    // cout << cnt;
    return 0;
}

// #include <stdio.h> // 思路：将从0到31这32个十进制数转换为二进制
// #include <math.h>
// int main()
// {
//     int end = (int)(pow(2, 5) - 1);
//     for (int i = 0; i <= end; i++)
//     {
//         printf("%d%d%d%d%d\n", i / 16 % 2, i / 8 % 2, i / 4 % 2, i / 2 % 2, i % 2);
//         // printf("%d%d%d%d%d\n", i % 32 / 16, i % 16 / 8, i % 8 / 4, i % 4 / 2, i % 2);
//     }
//     return 0;
// }
