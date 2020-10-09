// 六角填数
/*
如图所示六角形中，填入1~12的数字。使得每条直线上的数字之和都相同。
图中，已经替你填好了3个数字，请你计算星号位置所代表的数字是多少？

输出：10
*/

#include <stdio.h>
const int N = 12;

void fill(int x, int *seat, bool *visited)
{
    if (x == 1 || x == 2 || x == 12) // 第1、2、12号单元上的数字已经确定了，所以不必再对这三个单元上可以放置的数字进行讨论
    {
        fill(x + 1, seat, visited);
    }

    if (x > 12)
    {
        int sum[6];
        sum[0] = seat[1] + seat[3] + seat[6] + seat[8];
        sum[1] = seat[1] + seat[4] + seat[7] + seat[11];
        sum[2] = seat[2] + seat[3] + seat[4] + seat[5];
        sum[3] = seat[2] + seat[6] + seat[9] + seat[12];
        sum[4] = seat[8] + seat[9] + seat[10] + seat[11];
        sum[5] = seat[12] + seat[10] + seat[7] + seat[5];

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (sum[i] != sum[j])
                    return;
            }
        }
        printf("%d", seat[6]);
        return;
    }

    for (int i = 1; i <= 12; i++)
    {
        if (visited[i] == false && i != 1 && i != 3 && i != 8)
        {
            seat[x] = i;
            visited[i] = true;
            fill(x + 1, seat, visited);
            visited[i] = 0;
        }
    }
}

int main()
{
    int seat[N + 1] = {0};
    bool visited[N] = {false};

    seat[1] = 1;
    visited[1] = true;
    seat[2] = 8;
    visited[8] = true;
    seat[12] = 3;
    visited[3] = true;

    fill(1, seat, visited);

    return 0;
}
