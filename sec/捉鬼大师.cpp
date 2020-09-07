// 捉鬼大师
/*
世界上有鬼吗？如果有，那就一定有捉鬼大师，但是捉鬼大师的能力有限，他们只能消灭位于他们东南面的鬼，也就是说，如果把捉鬼大师的位置视为原点，那么他们只能消灭第四象限的鬼怪（位于 X 轴的正半轴，Y 的负半轴）。
现在给出一些鬼的坐标和一些捉鬼大师的坐标，请问有多少鬼不能消灭？
1.	输入：
第一行：给出两个数字 g,b 对应于 鬼的个数 和 捉鬼大师的个数。
接下来的g行，每行两个整数，是每个鬼的坐标（之间用空格隔开），
再接下来的b行，每行两个整数，是每个捉鬼大师的坐标（之间用空格个隔开），不会有重复的鬼和捉鬼大师出现。
2.	输出：
无法被消灭的鬼的坐标x,y之间用一个空格隔开，注意这些坐标输出顺序必须按照y值的降序排列，当y相等时，则按照x的降序排列
*/
/*
范例输入：
5 2
4 2
2 2
1 1
1 -2
2 -3
3 2
0 -1
输出：
1 1
2 2
4 2
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct gxy
{
    int x;
    int y;
} GXY;
typedef struct bxy
{
    int x;
    int y;
} BXY;
int g, b; // 鬼的个数和捉鬼大师的个数

void result(GXY *gArr, BXY *bArr)
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < g; j++)
        {
            if ((gArr[j].x > bArr[i].x && gArr[j].y < bArr[i].y) && j < g - 1)
            {
                // gArr[j].x = gArr[j + 1].x;
                // gArr[j].y = gArr[j + 1].y;
                gArr[j] = gArr[j + 1];
                g--;
            }
            if ((gArr[j].x > bArr[i].x && gArr[j].y < bArr[i].y) && (j == g - 1))
                g--;
        }
    }
    for (int i = 0; i < g - 1; i++) // 排序
    {
        for (int j = 0; j < g - 1 - i; j++)
        {
            if (gArr[j].y > gArr[j + 1].y)
            {
                GXY temp;
                temp = gArr[j];
                gArr[j] = gArr[j + 1];
                gArr[j + 1] = temp;
            }
            else if (gArr[j].y == gArr[j + 1].y && gArr[j].x > gArr[j + 1].x)
            {
                GXY temp;
                temp = gArr[j];
                gArr[j] = gArr[j + 1];
                gArr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < g; i++) //输出
    {
        printf("%d %d\n", gArr[i].x, gArr[i].y);
    }
}
int main()
{
    scanf("%d%d", &g, &b);

    GXY *gArr = (GXY *)malloc(g * sizeof(GXY)); //动态数组
    BXY *bArr = (BXY *)malloc(b * sizeof(BXY));

    for (int i = 0; i < g; i++)
    {
        scanf("%d%d", &gArr[i].x, &gArr[i].y);
    }

    for (int i = 0; i < b; i++)
    {
        scanf("%d%d", &bArr[i].x, &bArr[i].y);
    }

    result(gArr, bArr);

    return 0;
}
