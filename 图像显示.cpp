// 图像显示
/*
问题描述
编写一个程序，首先输入一个整数，例如 5，然后在屏幕上显示如下的图形（5 表示行数）：
* * * * *
* * * *
* * *
* *
*
*/
// #include <stdio.h>
// int main()
// {
//     int n;
//     int i, j;
//     scanf("%d", &n);
//     for (i = 0; i < 5; i++)
//     {
//         for (j = n - i; j > 0; j--)
//             printf("* "); // 每行结尾多输出一个空格不影响正确性
//         printf("\n");
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "* ";
        }
        cout << "*" << endl;
    }
    return 0;
}