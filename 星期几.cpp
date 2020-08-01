// 星期几
/*
1949年的国庆节（10 月 1 日）是星期六。今年（2012）的国庆节是星期一。
那么，从建国到现在，有几次国庆节正好是星期日呢？只要答案，不限手段！
可以用windows 日历，windows 计算器，Excel 公式，。。。。。当然，也可以编程！
不要求写出具体是哪些年，只要一个数目！

输出：9
*/
#include <stdio.h>
int days(int year);
int main()
{
    int cnt = 0; // 用来存储答案，从建国到现在，有cnt次国庆节正好是星期日
    int w = 6; // 1949年的国庆节（10 月 1 日）是星期六，所以初始化为6
    for (int year = 1950; year < 2013; year++)
    {
        w = (days(year) % 7 + w) % 7;
        if (w == 0)
        {
            cnt++;
        }
    }
    printf("%d", cnt);
}
int days(int year) // 这个函数用来计算特定年份的天数
{
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
    {
        return 366; // 闰年有366天
    }
    else
    {
        return 365;
    }
}
