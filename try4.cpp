#include <iostream>
using namespace std;
int main()
{
    char ch = 'a';
    cout << ch << endl;
    cout << toupper(ch) << endl;
    cout << ch << endl; // 可见toupper函数并不会改变所输入的字符的大小写
    return 0;
}