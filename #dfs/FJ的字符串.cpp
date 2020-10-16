// FJ的字符串
// AC
/* 
问题描述
FJ在沙盘上写了这样⼀些字符串：
A1 = “A”
A2 = “ABA”
A3 = “ABACABA”
A4 = “ABACABADABACABA”
……
你能找出其中的规律并写所有的数列AN吗？

输⼊格式
仅有⼀个数：N≤26。

输出格式
请输出相应的字符串AN，以⼀个换⾏符结束。输出中不得含有多余的空格或换⾏、回⻋符。

样例输⼊
3
样例输出
ABACABA
*/
#include <iostream> // AC
using namespace std;
string dfs(int N)
{
    if (N == 1)
    {
        // cout << "if" << endl;
        return "A";
    }
    else
    {
        // cout << "else" << endl;
        return dfs(N - 1) + (char)(N + 'A' - 1) + dfs(N - 1);
    }
}
int main()
{
    int N;
    cin >> N;
    // cout << dfs(N); // AC
    cout << dfs(N) << endl; // AC
    return 0;
}