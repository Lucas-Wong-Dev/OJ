// 4-2找公倍数
// AC
/*
问题描述
打印出1-1000所有11和17的公倍数。
*/
#include <stdio.h>
int main()
{
    for (int i = 17; i <= 1000; i++)
    {
        if (i % 11 == 0 && i % 17 == 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}