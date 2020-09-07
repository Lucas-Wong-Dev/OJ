// 六角填数
/*
如图所示六角形中，填入1~12的数字。使得每条直线上的数字之和都相同。
图中，已经替你填好了3个数字，请你计算星号位置所代表的数字是多少？

输出：10
*/

#include <stdio.h>
const int N = 12 + 1;
bool visited[N];
int a[N];
void fill(int x);
int main()
{
    a[1] = 1;
    visited[1] = true;
    a[2] = 8;
    visited[8] = true;
    a[12] = 3;
    visited[3] = true;
    fill(1);
    return 0;
}

void fill(int x)
{
    if (x == 1 || x == 2 || x == 12) // 第1、2、12号单元上的数字已经确定了，所以不必再对这三个单元上可以放置的数字进行讨论
    {
        fill(x + 1);
    }

    if (x > 12)
    {
        int sum[6];
        sum[0] = a[1] + a[3] + a[6] + a[8];
        sum[1] = a[1] + a[4] + a[7] + a[11];
        sum[2] = a[2] + a[3] + a[4] + a[5];
        sum[3] = a[2] + a[6] + a[9] + a[12];
        sum[4] = a[8] + a[9] + a[10] + a[11];
        sum[5] = a[12] + a[10] + a[7] + a[5];

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (sum[i] != sum[j])
                    return;
            }
        }
        printf("%d", a[6]);
        return;
    }

    for (int i = 1; i <= 12; i++)
    {
        if (visited[i] == 0 && i != 1 && i != 3 && i != 8)
        {
            a[x] = i;
            visited[i] = true;
            fill(x + 1);
            visited[i] = 0;
        }
    }
}