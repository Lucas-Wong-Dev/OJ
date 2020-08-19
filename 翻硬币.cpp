// 翻硬币
/*
小明正在玩一个“翻硬币”的游戏。桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母， 不是零）。
比如，可能情形是：**oo***oooo
如果同时翻转左边的两个硬币，则变为：oooo***oooo
现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,那么对特定的局面，最少要翻动多少次呢？
我们约定：把翻动相邻的两个硬币叫做一步操作，那么要求： 

输入格式
两行等长的字符串，分别表示初始状态和要达到的目标状态。每行的长度<1000 

输出格式
一个整数，表示最小操作步数。

样例输入1
**********
o****o****
样例输出1
5

样例输入2
*o**o***o***
*o***o**o*** 
样例输出2
1
*/
// 分析：贪心算法，从前往后遍历初始状态字符串，如果发现当前硬币和目标硬币不一样，则同时翻转这枚硬币和下一枚硬币
#include <string.h>
#include <stdio.h>
const int N = 1000;
void turn(char *c, int k) //只会改变自己和相邻
{
    for (int i = k; i <= k + 1; i++)
    {
        if (c[i] == '*')
        {
            c[i] = 'o';
        }
        else if (c[i] == 'o')
        {
            c[i] = '*';
        }
    }
}
int handle(char *originalState, char *targetState)
{
    int count = 0;
    char temp[N];
    strcpy(temp, originalState);

    for (int i = 0; temp[i] != '\0'; i++)
    {
        if (temp[i] != targetState[i])
        {
            turn(temp, i);
            count++;
            // printf("%s %d\n", temp, count);
        }
    }

    return count;
}

int main()
{
    char originalState[N] = {0}, targetState[N] = {0};

    // scanf("%s", originalState);
    // getchar(); // 必须要有getchar()
    // scanf("%s", targetState);

    gets(originalState); // 位于stdio.h
    gets(targetState);

    printf("%d", handle(originalState, targetState));
    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     int cnt = 0;
//     string s1, s2;
//     cin >> s1 >> s2;
//     for (int i = 0; i < s1.length(); i++)
//     {
//         if (s1[i] != s2[i])
//         {
//             if (s1[i] == 'o')
//                 s1[i] = '*';
//             else
//                 s1[i] = 'o';
//             if (s1[i + 1] == 'o')
//                 s1[i + 1] = '*';
//             else
//                 s1[i + 1] = 'o';
//             cnt++;
//         }
//     }
//     cout << cnt;
//     return 0;
// }