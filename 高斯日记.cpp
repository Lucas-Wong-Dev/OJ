// 高斯日记
/*
高斯日记
大数学家高斯有个好习惯，无论如何都要记日记。
他的日记有个与众不同的地方，他从不注明年月日，而是用一个整数代替。比如， 4210 后来人们知道那个整数就是日期，它表示那一天是高斯出生后的第几天。这或许也是个好习惯，它时时刻刻提醒着主人，日子又过去一天。还有多少时光可以用于浪费呢

高斯出生于 1777 年 4 月 30 日。

在高斯发现的一个重要定理的日记上标注着 5343。
因此可算出那天是 1791 年12 月 15 日。

高斯获得博士学位的那天日记上标着 8113
请你算出高斯获得博士学位的年月日。
提交答案的格式是yyyy-mm-dd, 例如 1980-03-21
输出： 1799-7-16
*/

#include <stdio.h>
bool isLeapYear(int year) //判断是否是闰年
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int main()
{
    int year = 1791, month = 12, day = 15;
    int daysVisited = 0, gap = 8113 - 5343;
    // daysVisited：已经遍历了daysVisited天
    // gap：高斯获得博士学位的那天 与 高斯发现一个重要定理那天 之差
    int daysUnvisited = 0;
    int arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 一年中每个月的天数
    int i = 11; // 这个i就是arr数组的下标，i等于11意味着当前月份是12月
    while(daysVisited <= gap)
    {
        if (i >= 12) // 如果已经遍历完了当前年份
        {
            i = 0; // 将表示月份的变量i重新置为0，也就是将月份重新置为一月份（注意这里的一月份是新的一年的一月份）
            year++; // 更新高斯获得博士学位的那天所在的年份
        }

        if (isLeapYear(year))
        {
            arr[1] = 29;
        }
        else
        {
            arr[1] = 28;
        }

        daysUnvisited = gap - daysVisited;
        // printf("daysUnvisited==%d ", daysUnvisited);
        daysVisited += arr[i];
        // printf("daysVisited==%d ", daysVisited);
        month = i + 1; // 更新高斯获得博士学位的那天所在的月份，注意arr数组是从下标为0的单元开始存放数据的，所以month应当等于数组下标加一
        // printf("month==%d ", month);
        i++;
        // printf("\n");
    }
    printf("%d-%d-%d\n", year, month, day+daysUnvisited); // 天数还要加上原先的 15 天
    return 0;
}