// 7-1用宏求球的体积
// AC
/*
问题描述
使用宏实现计算球体体积的功能。用户输入半径，系统输出体积。不能使用函数，pi=3.1415926，结果精确到小数点后五位。

样例输入
一个满足题目要求的输入范例。
例：
1.0

样例输出
4.18879

数据规模和约定
输入数据中每一个数的范围。
数据表示采用double类型。
*/
#include <stdio.h>
const double pi = 3.1415926;
#define getVolume(r) 4.0 * (pi) * (r) * (r) * (r) / 3.0
int main()
{
    double r;
    scanf("%lf", &r);
    double v = getVolume(r);
    printf("%.5lf\n", v);
    return 0;
}