// 矩形的面积交
/*
问题描述
平面上有两个矩形，它们的边平行于直角坐标系的X轴或Y轴。对于每个矩形，我们给出它的一对相对顶点的坐标，请你编程算出两个矩形的交的面积。

输入格式
输入仅包含两行，每行描述一个矩形。
在每行中，给出矩形的一对相对顶点的坐标，每个点的坐标都用两个绝对值不超过10^7的实数表示。

输出格式
输出仅包含一个实数，为交的面积，保留到小数后两位。

样例输入
1 1 3 3
2 2 4 4

样例输出
1.00
*/
#include <algorithm>
#include <iostream>
using namespace std;

struct rectangle
{
    double x1, y1; // 左上角点坐标
    double x2, y2; // 右下角点坐标
};

void adjustRectangle(rectangle &sq)
{
    // 将矩形标准化，即将结构体中的(x1, y1), (x2, y2)分别赋值为该矩形左上角和右下角的点的坐标
    if (sq.x1 > sq.x2)
    {
        swap(sq.x1, sq.x2);
    }
    if (sq.y1 < sq.y2)
    {
        swap(sq.y1, sq.y2);
    }
}

double getRectangleArea(rectangle &sq)
{
    // 计算标准化矩形的面积
    double res = (sq.x2 - sq.x1) * (sq.y1 - sq.y2);
    return res;
}

rectangle getCrossRectangle(rectangle s1, rectangle s2)
{
    // 求两个标准化矩形的相交矩形
    if (s1.x1 > s2.x1)
    {
        swap(s1, s2);
    }
    return s1.x2 < s2.x1 || s1.y2 > s2.y1
               ? rectangle{0, 0, 0, 0}
               : rectangle{
                     max(s1.x1, s2.x1),
                     min(s1.y1, s2.y1),
                     min(s1.x2, s2.x2),
                     max(s1.y2, s2.y2)};
}

istream &operator>>(istream &in, rectangle &sq)
{
    // 输入矩形
    in >> sq.x1 >> sq.y1 >> sq.x2 >> sq.y2;
    adjustRectangle(sq);
    return in;
}

int main()
{
    rectangle s1, s2;
    cin >> s1 >> s2;
    rectangle cross = getCrossRectangle(s1, s2);
    printf("%.2lf\n", getRectangleArea(cross));
    return 0;
}