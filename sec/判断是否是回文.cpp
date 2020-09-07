// 判断回文
// AC
/*
编程判断一个字符串是否是回文，当字符串是回文时，输出字符串：yes!，否则输出字符串：no!。
所谓回文即正向与反向的拼写都一样，如adgda。
长度在100以内，且全为小写字母
样例输入adgda
样例输出yes!
*/
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
            // cout << "no!"; // AC
            cout << "no!" << endl; // AC
            return 0;
        }
        i++;
        j--;
    }
    // cout << "yes!"; // AC
    cout << "yes!" << endl; // AC
    return 0;
}