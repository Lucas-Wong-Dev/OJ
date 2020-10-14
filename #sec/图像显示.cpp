// 图像显示
// AC
/*
问题描述
编写一个程序，首先输入一个整数，例如 5，然后在屏幕上显示如下的图形（5 表示行数）：
* * * * *
* * * *
* * *
* *
*
*/
#include <iostream> // AC：已在蓝桥练习系统通过
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "* ";
        }
        cout << "*" << endl;
    }
    return 0;
}

// #include <stdio.h> // 已在蓝桥练习系统通过
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = n - i + 1; j >= 1; j--)
//             printf("* "); // 每行结尾多输出一个空格不影响正确性
//         printf("\n");
//     }
//     return 0;
// }