// 三角形面积
// AC
/*
问题描述
由三角形的三边长，求其面积。
提示：由三角形的三边a,b,c求面积可以用如下的公式：
// 见图片

输入格式
由空格分开的三个整数。
输出格式
一个实数，保留两位小数。

样例输入
3 4 5
样例输出
6.00

数据规模和约定
输入的三条边一定能构成三角形，不用进行判定。a,b,c小于1000
*/

#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double t = (a + b + c) / 2;
    double area = sqrt(t * (t - a) * (t - b) * (t - c));

    printf("%.2lf\n", area);
    return 0;
}