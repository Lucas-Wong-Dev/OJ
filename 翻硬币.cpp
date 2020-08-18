// 翻硬币
/*
小明正在玩一个“翻硬币”的游戏。桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母， 不是零）。
比如，可能情形是：**oo***oooo
如果同时翻转左边的两个硬币，则变为：oooo***oooo
现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,那么对特定的局面，最少要翻动多少次呢？
我们约定：把翻动相邻的两个硬币叫做一步操作，那么要求： 

程序输入：
两行等长的字符串，分别表示初始状态和要达到的目标状态。每行的长度<1000 

程序输出：
一个整数，表示最小操作步数。

例如：
用户输入：
**********
o****o****
程序应该输出：
5

再例如：
用户输入：
*o**o***o***
*o***o**o*** 
程序应该输出： 
1
*/
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
