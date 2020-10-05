// 高精度加法
// AC
/*
问题描述
输入两个整数a和b，输出这两个整数的和。a和b都不超过 100 位。

算法描述
由于a 和b 都比较大，所以不能直接使用语言中的标准数据类型来存储。对于这种问题，一般使用数组来处理。
定义一个数组A，A[0]用于存储a的个位，A[1]用于存储a的十位，依此类推。同样可以用一个数组B来存储b。
计算c = a + b 的时候，首先将A[0]与B[0]相加，如果有进位产生，则把进位（即和的十位数）存入 r，把和的个位数存入 C[0]，即C[0]等于(A[0]+B[0])%10。
然后计算A[1]与B[1]相加，这时还应将低位进上来的值r也加起来，即C[1]应该是A[1]、B[1]和 r 三个数的和。在计算C[1]时，如果又有进位产生，则仍可将新的进位存入到r中，和的个位存到C[1]中。
依此类推，即可求出c的所有位。
最后将c出即可。

输入格式
输入包括两行，第一行为一个非负整数a，第二行为一个非负整数b。两个整数都不超过100位，两数的最高位都不是0。

输出格式
输出一行，表示 a + b 的值。

样例输入
20100122201001221234567890
2010012220100122
样例输出
20100122203011233454668012
*/
#include <stdio.h> // AC
#include <string.h>
int main()
{
    char a[100 + 1], b[100 + 1], ans[100 + 1 + 1] = {0};
    scanf("%s%s", a, b);
    int lena = strlen(a);
    int lenb = strlen(b);

    for (int i = 0; i < lena || i < lenb; i++)
    {
        if (i < lena)
        {
            ans[i] += a[lena - i - 1] - '0';
        }
        if (i < lenb)
        {
            ans[i] += b[lenb - i - 1] - '0';
        }
        if (ans[i] >= 10)
        {
            ans[i + 1] = ans[i] / 10;
            ans[i] %= 10;
        }
    }

    int maxIndex = (lena > lenb ? lena : lenb);

    if (ans[maxIndex] > 0)
        printf("%d", ans[maxIndex]);
    for (int i = maxIndex - 1; i >= 0; i--)
        printf("%d", ans[i]);
    return 0;
}

// #include <iostream> // AC
// #include <string>
// #include <algorithm> // 要用到max函数
// using namespace std;
// int main()
// {
//     string a;
//     string b;
//     int A[100] = {0};
//     int B[100] = {0};
//     cin >> a >> b;
//     int lena = a.length(), lenb = b.length();
//     int index = 0;
//     for (int i = lena - 1; i >= 0; i--)
//     {
//         A[index++] = a[i] - '0';
//     }
//     index = 0;
//     for (int i = lenb - 1; i >= 0; i--)
//     {
//         B[index++] = b[i] - '0';
//     }
//     int C[100+1] = {0};
//     int temp = 0;
//     for (int i = 0; i < 100; i++)
//     {
//         C[i] = A[i] + B[i] + temp;
//         temp = C[i] / 10;
//         C[i] = C[i] % 10;
//     }
//     // int max = lena;
//     // if (max < lenb)
//     //     max = lenb;
//     int maxIndex = max(lena, lenb) - 1; // maxIndex是数组C中已使用的数组元素的最大下标
//     if (C[maxIndex + 1] != 0)
//         maxIndex = maxIndex + 1;
//     for (int i = maxIndex; i >= 0; i--)
//     {
//         cout << C[i];
//     }
//     return 0;
// }