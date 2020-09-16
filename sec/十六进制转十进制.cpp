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
#include <iostream>
using namespace std;
int main()
{
    long long a; // 这里使用long long来存储所输入的数据，以防因输入数据过大而导致的溢出
    scanf("%x", &a);
    printf("%lld", a);
    return 0;
}