// 报时助手
/*
问题描述
给定当前的时间，请用英文的读法将它读出来。
时间用时h和分m表示，在英文的读法中，读一个时间的方法是：
如果m为0，则将时读出来，然后加上“o'clock”，如 3:00  读作“three o'clock”。
如果m 不为 0，则将时读出来，然后将分读出来，如 5:30 读作“five thirty”。

时和分的读法使用的是英文数字的读法，其中 0~20读作：
0:zero, 1: one, 2:two, 3:three, 4:four, 5:five, 6:six, 7:seven, 8:eight, 9:nine, 10:ten,11:eleven, 12:twelve, 13:thirteen, 14:fourteen, 15:fifteen, 16:sixteen, 17:seventeen, 18:eighteen, 19:nineteen, 20:twenty。

30 读作thirty，40 读作forty，50 读作fifty。

对于大于 20 小于 60 的数字，首先读整十的数，然后再加上个位数。如 31 首先读30 再加 1 的读法，读作“thirty one”。按上面的规则 21:54 读作“twenty one fifty four”，9:07 读作“nine seven”，0:15读作“zero fifteen”。

输入格式
输入包含两个非负整数h和m，表示时间的时和分。非零的数字前没有前导 0。
h小于 24，m 小于 60。

输出格式
输出时间时刻的英文。

样例输入
0 15
样例输出
zero fifteen
*/
#include <stdio.h>
int main()
{
    char *en0to19[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *en20to50[] = {"twenty", "thirty", "forty", "fifty"};
    char *oclick = "o'clock";

    int h, m;
    scanf("%d%d", &h, &m);

    if (h >= 20)
    {
        printf("%s", en20to50[0]);
        if (h % 20 > 0)
            printf(" %s", en0to19[h % 20]);
    }
    else
    {
        printf("%s", en0to19[h]);
    }

    if (m == 0)
    {
        printf(" %s", oclick);
    }
    else if (m >= 20)
    {
        printf(" %s", en20to50[m / 10 - 2]);
        if (m % 10 > 0)
            printf(" %s", en0to19[m % 10]);
    }
    else
    {
        printf(" %s", en0to19[m]);
    }

    return 0;
}
