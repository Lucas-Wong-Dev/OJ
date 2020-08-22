// Sine之舞
/*
问题描述
最近FJ为他的奶牛们开设了数学分析课，FJ 知道若要学好这门课，必须有一个好的三角函数基本功。所以他准备和奶牛们做一个“Sine 之舞”的游戏，寓教于乐，提高奶牛们的计算能力。
不妨设
An=sin(1–sin(2+sin(3–sin(4+...sin(n))...)
Sn=(...(A1+n)A2+n-1)A3+...+2)An+1

FJ 想让奶牛们计算 Sn 的值，请你帮助FJ打印出Sn的完整表达式，以方便奶牛们做题。

输入格式
仅有一个数：N<201。

输出格式
请输出相应的表达式Sn，以一个换行符结束。输出中不得含有多余的空格或换行、回车符。

样例输入
3
样例输出
((sin(1)+3)sin(1–sin(2))+2)sin(1–sin(2+sin(3)))+1
*/
#include <iostream>
using namespace std;
int main()
{
    string a[201];
    string s;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            a[i] = "sin(1";
            // cout << a[i] << endl;
            continue;
        }
        a[i] = a[i - 1];
        if (i % 2 == 1)
        {
            a[i] += "-";
        }
        else
        {
            a[i] += "+";
        }
        a[i] += "sin(";
        a[i] += (char)(i + '1');
        // cout << a[i] << endl;
    }
    // cout << "------------" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            a[i] += ")";
            // cout << a[i] << endl;
        }
        // cout << "---" << endl;
    }
    // cout << "------------" << endl;
    for (int i = 2; i <= N; i++)
    {
        s += "(";
    }
    for (int i = N - 1; i >= 1; i--)
    {
        s += a[N - 1 - i];
        s += "+";
        s += (char)(i + 1 + '0');
        s += ")";
    }
    s += a[N - 1];
    s += "+1";
    cout << s;
    return 0;
}