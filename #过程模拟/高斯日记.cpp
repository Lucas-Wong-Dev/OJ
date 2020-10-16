// 高斯日记
/*
大数学家高斯有个好习惯，无论如何都要记日记。
他的日记有个与众不同的地方，他从不注明年月日，而是用一个整数代替。比如， 4210 后来人们知道那个整数就是日期，它表示那一天是高斯出生后的第几天。这或许也是个好习惯，它时时刻刻提醒着主人，日子又过去一天。还有多少时光可以用于浪费呢

高斯出生于1777年4月30日。

在高斯发现的一个重要定理的日记上标注着5343。
因此可算出那天是1791年12月15日。

高斯获得博士学位的那天日记上标着8113
请你算出高斯获得博士学位的年月日。
提交答案的格式是yyyy-mm-dd, 例如 1980-03-21
输出：1799-7-16
*/
#include <stdio.h>

const int days_in_month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) ||
           (year % 400 == 0);
}

int main()
{
    int year = 1777;
    int month = 5;
    int day = 0; // 把4月30日视为5月0日

    int last = 8113 - 1;

    while (last > 0)
    {
        bool leap = isLeapYear(year);
        if (last > (leap ? 366 : 365))
        {
            last -= (leap ? 366 : 365);
            year++;
        }
        else if (last > days_in_month[month])
        {
            last -= (month == 2 && leap == false ? 28 : days_in_month[month]);
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
        else
        {
            day = last;
            last = 0;
            break;
        }
    }
    printf("%d-%d-%d\n", year, month, day);
    return 0;
}

// #include <iostream>
// using namespace std;

// int month[2][12 + 1] = {
//     {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

// bool isLeapYear(int n)
// {
//     if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
//     {
//         return true;
//     }
//     else
//         return false;
// }

// int main()
// {
//     int y = 1777, m = 4, d = 30;
//     int last = 8113 - 1; // 加上了出生的那一天

//     while (last > 0)
//     {
//         last--;
//         d++;

//         if (d > month[isLeapYear(y)][m])
//         {
//             d = 1;
//             m++;
//         }
//         if (m > 12) // 如果已经遍历完了当前年份
//         {
//             m = 1; // 将表示月份的变量m重新置为1，也就是将月份重新置为一月份（注意这里的一月份是新的一年的一月份）
//             y++;   // 更新高斯获得博士学位的那天所在的年份
//         }
//     }

//     cout << y << "-" << m << "-" << d << endl;
//     return 0;
// }