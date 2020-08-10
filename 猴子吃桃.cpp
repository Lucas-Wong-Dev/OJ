// 猴子吃桃
/*
小猴子第一天摘下若干桃子,当即吃掉一半,又多吃一个.
第二天早上又将剩下的桃子吃一半,又多吃一个.
以后每天早上吃前一天剩下的一半另一个.
到第 10 天早上猴子想再吃时发现,只剩下一个桃子了.
问第一天猴子共摘多少个桃子？ 
输出：
1534
*/
#include <stdio.h>
//从反面考虑，用递归解决
int fruit(int numOfPeach, int times) // 今天是倒数第times天，今天在小猴吃桃前还剩下numOfPeach个桃子
{
    if (times == 10) // 今天是倒数第10天，也就是整数第一天。今天在小猴吃桃前还剩下numOfPeach个桃子，这个numOfPeach就是小猴子摘下来的桃子的数量
        return numOfPeach;
    return fruit((numOfPeach + 1) * 2, times + 1);
}

int main()
{
    printf("%d\n", fruit(1, 1));
    return 0;
}
