// 闰年的判断
/*
输入：
2014
输出：
is not
输入：
2008
输出：
is
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int year;
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        printf("is\n", year);
    else
        printf("is not\n", year);
    return 0;
}