// 字母图形
/*
ABCDEFG 
BABCDEF 
CBABCDE 
DCBABCD 
EDCBABC
这是一个5行7列的图形，请找出这个图形的规律，并输出一个n行m列的图形。

输入格式
输入一行，包含两个整数n和m，分别表示你要输出的图形的行数的列数。

输出格式
输出n行，每个m个字符，为你的图形。

样例输入
5 7

样例输出
ABCDEFG 
BABCDEF 
CBABCDE 
DCBABCD 
EDCBABC
 
数据规模与约定
1 <= n, m <= 26。
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << char('A' + abs(i - j));
        }
        cout << endl;
    }
    return 0;
}
