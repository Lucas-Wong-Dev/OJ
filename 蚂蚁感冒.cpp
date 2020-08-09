// 蚂蚁感冒
/*蚂蚁感冒
长100厘米的细长直杆子上有n只蚂蚁。它们的头有的朝左，有的朝右。
每只蚂蚁都只能沿着杆子向前爬，速度是1厘米/秒。
当两只蚂蚁碰面时，它们会同时掉头往相反的方向爬行。
这些蚂蚁中，有1只蚂蚁感冒了。并且在和其它蚂蚁碰面时，会把感冒传染给碰到的蚂蚁。
请你计算，当所有蚂蚁都爬离杆子时，有多少只蚂蚁患上了感冒。

输入格式
第一行输入一个整数n(1<n<50), 表示蚂蚁的总数。
接着的一行是n个用空格分开的整数Xi(-100 < Xi < 100), Xi的绝对值，表示蚂蚁离开杆子左边端点的距离。正值表示头朝右，负值表示头朝左，数据中不会出现 0 值，也不会出现两只蚂蚁占用同一位置。其中，第一个数据代表的蚂蚁感冒了。

要求输出1个整数，表示最后感冒蚂蚁的数目。

例如，输入：
3
5 -2 8
程序应输出：
1

再例如，输入：
5
-10 8 -20 12 25
程序应输出：
3
*/
// #include <stdio.h>
// #include <math.h>
// const int N = 50;
// void fun(int x[N][2], int n, int numOfAntOnPole, int numOfSickAnt)
// {
//     if (numOfAntOnPole == 0) //如果现在杆子上的蚂蚁总数为0
//     {
//         printf("%d\n", numOfSickAnt);
//         return;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (fabs(x[i][0]) == 100 || (x[i][0] == 0)) //爬离杆子
//         {
//             numOfAntOnPole--;
//             x[i][0] = 101; //表示编号为i的蚂蚁已经不在杆子上了
//         }
//         for (int j = 0; j < n; j++)
//         {
//             if (i != j)
//             {
//                 if (x[i][0] == -x[j][0] && x[i][0] != 101 && x[j][0] != 101)
//                 {
//                     x[i][0] = -x[i][0];         // 将第i只蚂蚁的前进方向置反
//                     x[j][0] = -x[j][0];         // 将第j只蚂蚁的前进方向置反
//                     if (x[i][1] + x[j][1] == 1) //如果一方感冒
//                     {
//                         x[i][1] = 1;    // 将第i只蚂蚁置为感冒
//                         x[j][1] = 1;    // 将第j只蚂蚁置为感冒
//                         numOfSickAnt++; // 两只蚂蚁碰面时，只有当其中一只感冒，另一只没有感冒，感冒蚂蚁的只数才会增加
//                     }
//                 }
//             }
//         }
//         if (x[i][0] != 101 && x[i][0] != 0 && x[i][0] != 100)
//         {
//             x[i][0]++;
//         }
//     }
//     fun(x, n, numOfAntOnPole, numOfSickAnt);
// }
// int main()
// {
//     int x[N][2];
//     int numOfAntOnPole; //杆子上的蚂蚁总数
//     int numOfSickAnt;   //杆子上感冒的蚂蚁总数
//     int n;              //蚂蚁的总数
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &x[i][0]);
//         x[i][1] = 0;
//     }
//     x[0][1] = 1; // 第一只蚂蚁是感冒的
//     fun(x, n, n, 1);
//     return 0;
// }

// 分析：
// 两只蚂蚁相遇，它们各自掉头，不妨视相遇为交换身体，这样和各走各的效果一样的
// lr：在 最初的那个感冒了的蚂蚁 左面 且 往右爬 的蚂蚁数量
// ll：在 最初的那个感冒了的蚂蚁 左面 且 往左爬 的蚂蚁数量
// rl：在 最初的那个感冒了的蚂蚁 右面 且 往左爬 的蚂蚁数量
// rr：在 最初的那个感冒了的蚂蚁 右面 且 往右爬 的蚂蚁数量
// 如果最初的那个感冒了的蚂蚁往左爬，那么它会感染lr个蚂蚁，同时如果lr>0，那么这lr个蚂蚁还会再感染rl个蚂蚁，即答案为lr + rl + 1；如果lr=0，那感冒不会被感染给lr个蚂蚁，更不会被感染给rl个蚂蚁，即答案为1，也就是说只有最开始的那只是感冒的
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, theOriginalAnt, t, ll = 0, lr = 0, rl = 0, rr = 0, ans = 0;
    // n：蚂蚁的总数
    // theOriginalAnt：最初的那个感冒了的蚂蚁的方向和位置
    // ans：最后感冒蚂蚁的数目
    cin >> n >> theOriginalAnt;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> t;
        if (t > 0) // 这只蚂蚁头朝右
        {
            if (abs(t) < abs(theOriginalAnt))
                lr++;
            else
                rr++;
        }
        else // 这只蚂蚁头朝左
        {
            if (abs(t) < abs(theOriginalAnt))
                ll++;
            else
                rl++;
        }
    }
    if (theOriginalAnt < 0) // 如果最初的那个感冒了的蚂蚁头朝左
    {
        if (lr > 0)
            ans = lr + rl + 1;
        else
            ans = 1;
    }
    else // 如果最初的那个感冒了的蚂蚁头朝右
    {
        if (rl > 0)
            ans = rl + lr + 1;
        else
            ans = 1;
    }
    cout << ans;
    return 0;
}
