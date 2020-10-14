// Sine之舞
// AC
/*
问题描述
最近FJ为他的奶牛们开设了数学分析课，FJ知道若要学好这门课，必须有一个好的三角函数基本功。所以他准备和奶牛们做一个“Sine 之舞”的游戏，寓教于乐，提高奶牛们的计算能力。
不妨设
An=sin(1–sin(2+sin(3–sin(4+...sin(n))...)
Sn=(...(A1+n)A2+n-1)A3+...+2)An+1

FJ想让奶牛们计算Sn的值，请你帮助FJ打印出Sn的完整表达式，以方便奶牛们做题。

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
const int N_MAX = 200;
int main()
{
    int N;
    cin >> N;
    string A[N_MAX + 1];

    string S;

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            A[i] = "sin(1";
            // cout << A[i] << endl; //
            continue;
        }
        A[i] = A[i - 1];
        if (i % 2 == 1)
        {
            // A[i] += "-"; // AC 中、英文状态下输入的
            A[i] += "–"; // AC 样例输出中的
        }
        else
        {
            A[i] += "+";
        }
        A[i] += "sin(";
        A[i] += (char)(i + '1');
        // cout << A[i] << endl; //
    }
    // cout << "------------" << endl; //
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            A[i] += ")";
        }
        // cout << A[i] << endl; //
    }
    // cout << "------------" << endl; //
    for (int i = 1; i <= N - 1; i++)
    {
        S += "(";
    }
    for (int i = N - 1; i >= 1; i--)
    {
        S += A[N - 1 - i];
        S += "+";
        S += (char)(i + 1 + '0');
        S += ")";
    }
    S += A[N - 1];
    S += "+1";
    cout << S << endl;
    return 0;
}