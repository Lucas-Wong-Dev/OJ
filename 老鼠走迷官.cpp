// 老鼠走迷官
/*
说明 
老鼠走迷宫是递回求解的基本题型，我们在二维阵列中
使用 2 表示迷宫墙壁，
使用 1 来表示老鼠的行走路径，
试以程式求出由入口至出口的路径。

解法
老鼠的走法有上、左、下、右四个方向，在每前进一格之后就选一个方向前进，无法前进时退回选择下一个可前进方向，如此在阵列中依序测试四个方向，直到走到出口为止，这是递回的基本题
*/
#include <stdio.h>
#include <stdlib.h>

bool visit(int, int);
int maze[7][7] = {{2, 2, 2, 2, 2, 2, 2},
                  {2, 0, 0, 0, 0, 0, 2},
                  {2, 0, 2, 0, 2, 0, 2},
                  {2, 0, 0, 2, 0, 2, 2},
                  {2, 2, 0, 2, 0, 2, 2},
                  {2, 0, 0, 0, 0, 0, 2},
                  {2, 2, 2, 2, 2, 2, 2}};
int startI = 1, startJ = 1; // 指定入口
int endI = 5, endJ = 5;     // 指定出口
bool hasFound = false; //用来标记visit函数的结果
int main()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
            if (maze[i][j] == 2)
                // printf("█");
                printf("2");
            else
                printf(" ");
        printf("\n");
    }
    printf("-------------\n");
    if (visit(startI, startJ) == false)
        printf("\nhaven't found\n");
    else
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (maze[i][j] == 2)
                    // printf("█");
                    printf("2");
                else if (maze[i][j] == 1)
                    // printf("◇");
                    printf("1");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
bool visit(int i, int j) //递归地求解老鼠该走的道路
{
    maze[i][j] = 1;
    if (i == endI && j == endJ) //如果到达了指定的出发点
        hasFound = true;
    if (hasFound != 1 && maze[i][j + 1] == 0)
        visit(i, j + 1);
    if (hasFound != 1 && maze[i + 1][j] == 0)
        visit(i + 1, j);
    if (hasFound != 1 && maze[i][j - 1] == 0)
        visit(i, j - 1);
    if (hasFound != 1 && maze[i - 1][j] == 0)
        visit(i - 1, j);
    if (!hasFound)
        maze[i][j] = 0;
    return hasFound;
}