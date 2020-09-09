// 杨辉三角形
// AC
/*
杨辉三角形又称Pascal三角形，它的第i+1行是(a+b)^i的展开式的系数。
它的一个重要性质是：三角形中的每个数字等于它两肩上的数字相加。
下面给出了了杨辉三角形的前4行：
1
1 1
1 2 1
1 3 3 1
给出n，输出它的前n行。

输入格式
输入包含一个数n。

输出格式
输出杨辉三角形的前n行。每一行从这一行的第一个数开始依次输出，中间使用一个空格分隔。请不要在前面输出多余的空格

数据规模与约定
1 <= n <= 34。
*/
#include <stdio.h>
#include <stdlib.h>

const int MAX_n = 34;

int main()
{
    int n;
    scanf("%d", &n);
    int a[MAX_n][MAX_n];
    // a[0][0] = 1; // 第一个数置为1都置1

    for (int i = 0; i < n; i++)
    {
        a[i][0] = 1; // 将每行的首位上的元素置为1
        a[i][i] = 1; // 将每行的主对角线位置上的元素置为1
        for (int j = 1; j < i; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}
