// 传球游戏-动态规划
// AC
// http://lx.lanqiao.cn/problem.page?gpid=T97
/*
问题描述
上体育课的时候，小蛮的老师经常带着同学们一起做游戏。这次，老师带着同学们一起做传球游戏。
游戏规则是这样的：n个同学站成一个圆圈，其中的一个同学手里拿着一个球，当老师吹哨子时开始传球，每个同学可以把球传给自己左右的两个同学中的一个（左右任意），当老师再次吹哨子时，传球停止，此时，拿着球没传出去的那个同学就是败者，要给大家表演一个节目。
聪明的小蛮提出一个有趣的问题：有多少种不同的传球方法可以使得从小蛮手里开始传的球，传了m次以后，又回到小蛮手里。两种传球的方法被视作不同的方法，当且仅当这两种方法中，接到球的同学按接球顺序组成的序列是不同的。比如有3个同学1号、2号、3号，并假设小蛮为1号，球传了3次回到小蛮手里的方式有1->2->3->1和1->3->2->1，共2种。

输入格式
共一行，有两个用空格隔开的整数n，m（3<=n<=30，1<=m<=30）。
输出格式
共一行，有一个整数，表示符合题意的方法数。

样例输入
3 3
样例输出
2

数据规模和约定
40%的数据满足：3<=n<=30，1<=m<=20
100%的数据满足：3<=n<=30，1<=m<=30
*/
/*
30 30
155117522

10 29
0

3 30
357913942

15 30
155117522
*/
#include <iostream> // AC
using namespace std;

const int MAX_n = 30;
const int MAX_m = 30;

int cycleSize = 0; // n
int stepLeft = 0;  // m

inline int Next(int k)
{
    return k == cycleSize ? 1 : k + 1;
}

inline int Prev(int k)
{
    return k == 1 ? cycleSize : k - 1;
}

int CalcCases(int cases[MAX_m + 1][MAX_n + 1])
{
    cases[0][1] = 1; // 当剩余步骤为0时如果球在1号手上，说明方案成立，cases[0][1]取1；如果球在别人手上，说明方案不成立，cases[0][1]取0

    for (int i = 1; i <= stepLeft; i++) // 从剩余步骤为1的情况开始递推
    {
        for (int j = 1; j <= cycleSize; j++)
        {
            cases[i][j] = cases[i - 1][Prev(j)] + cases[i - 1][Next(j)];
        }
    }

    return cases[stepLeft][1]; // cases[stepLeft][1] 表示剩余stepLeft步且球在1号同学手上时，球传回到1号同学的传球方案数
}

int main()
{
    int cases[MAX_m + 1][MAX_n + 1] = {0}; // cases[i][j] 表示剩余i步且在球在j号同学手上时，球传回到1号同学的传球方案数
    cin >> cycleSize >> stepLeft;          // n m
    cout << CalcCases(cases) << endl;
    return 0;
}

// #include <iostream> // AC
// using namespace std;
// const int MAX_n = 30;
// const int MAX_m = 30;

// inline int prev(int i, int n)
// {
//     return i == 1 ? n : i - 1;
// }
// inline int next(int i, int n)
// {
//     return i == n ? 1 : i + 1;
// }
// int calCases(int n, int m, int cases[MAX_n + 1][MAX_m + 1])
// {
//     cases[1][0] = 1;
//     for (int j = 1; j <= m; j++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             cases[i][j] = cases[prev(i, n)][j - 1] + cases[next(i, n)][j - 1];
//         }
//     }

//     return cases[1][m];
// }
// int main()
// {
//     int cases[MAX_n + 1][MAX_m + 1] = {0};
//     int n, m;
//     cin >> n >> m;
//     cout << calCases(n, m, cases) << endl;

//     return 0;
// }