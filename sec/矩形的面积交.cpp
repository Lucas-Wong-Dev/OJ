// 矩形面积交
// AC
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
// #include <algorithm> // AC 但存在warning
// #include <iostream>
// using namespace std;

// struct rectangle
// {
//     double x1, y1; // 左下角点坐标
//     double x2, y2; // 右上角点坐标
//     // 所以，在正常情况下，x1<y1并且y1<y2
//     // 以后做矩形的题（尤其是涉及到矩形之间位置关系的题），如果需要自行创建矩形结构体类型的话，最佳实践是在矩形结构体类型内设置两个坐标：矩形左下角点坐标和矩形右上角点坐标
//     // 好处1：有这两个坐标就可以唯一确定一个矩形了
//     // 好处2：在正常情况下，对于任意一个矩形，有如下结论：x1<y1并且y1<y2。你可以利用这一结论快速理清两矩形的位置关系。
// };

// void adjustRectangle(rectangle &rect)
// {
//     // 将矩形标准化，即将结构体中的(x1, y1), (x2, y2)分别赋值为该矩形左下角和右上角的点的坐标
//     if (rect.x1 > rect.x2)
//     {
//         swap(rect.x1, rect.x2);
//     }
//     if (rect.y1 > rect.y2)
//     {
//         swap(rect.y1, rect.y2);
//     }
// }

// double getRectangleArea(rectangle rect)
// {
//     // 计算标准化矩形的面积
//     double res = (rect.x2 - rect.x1) * (rect.y2 - rect.y1);
//     return res;
// }

// rectangle getCrossRectangle(rectangle rect1, rectangle rect2)
// {
//     // 求两个标准化矩形的相交矩形
//     if (rect1.x1 > rect2.x1)
//     {
//         swap(rect1, rect2);
//     }
//     return rect1.x2 <= rect2.x1 || rect1.y1 >= rect2.y2 || rect1.y2 <= rect2.y1
//                ? rectangle{0, 0, 0, 0}
//                : rectangle{
//                      max(rect1.x1, rect2.x1),
//                      max(rect1.y1, rect2.y1),
//                      min(rect1.x2, rect2.x2),
//                      min(rect1.y2, rect2.y2)};
// }

// istream &operator>>(istream &in, rectangle &rect)
// {
//     // 输入矩形
//     in >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
//     adjustRectangle(rect);
//     return in;
// }

// int main()
// {
//     rectangle rect1, rect2;
//     cin >> rect1 >> rect2;
//     rectangle crossRectangle = getCrossRectangle(rect1, rect2);
//     printf("%.2lf\n", getRectangleArea(crossRectangle));
//     return 0;
// }

#include <algorithm> // AC
#include <iostream>
using namespace std;

struct rectangle
{
    double x1, y1; // 左下角点坐标
    double x2, y2; // 右上角点坐标
    // 所以，在正常情况下，x1<y1并且y1<y2
    // 以后做矩形的题（尤其是涉及到矩形之间位置关系的题），如果需要自行创建矩形结构体类型的话，最佳实践是在矩形结构体类型内设置两个坐标：矩形左下角点坐标和矩形右上角点坐标
    // 好处1：有这两个坐标就可以唯一确定一个矩形了
    // 好处2：在正常情况下，对于任意一个矩形，有如下结论：x1<y1并且y1<y2。你可以利用这一结论快速理清两矩形的位置关系。
};

void adjustRectangle(rectangle &rect)
{
    // 将矩形标准化，即将结构体中的(x1, y1), (x2, y2)分别赋值为该矩形左下角和右上角的点的坐标
    if (rect.x1 > rect.x2)
    {
        swap(rect.x1, rect.x2);
    }
    if (rect.y1 > rect.y2)
    {
        swap(rect.y1, rect.y2);
    }
}

double getCrossRectangleArea(rectangle rect1, rectangle rect2)
{
    // 求两个标准化矩形的相交矩形的面积
    if (rect1.x1 > rect2.x1)
    {
        swap(rect1, rect2);
    }
    if (rect1.x2 <= rect2.x1 || rect1.y1 >= rect2.y2 || rect1.y2 <= rect2.y1)
    {
        return 0;
    }
    else
    {
        double width = (max(rect1.x1, rect2.x1) - min(rect1.x2, rect2.x2));
        double length = (max(rect1.y1, rect2.y1) - min(rect1.y2, rect2.y2));
        return width * length;
    }
}

istream &operator>>(istream &in, rectangle &rect)
{
    // 输入矩形
    in >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
    adjustRectangle(rect);
    return in;
}

int main()
{
    rectangle rect1, rect2;
    cin >> rect1 >> rect2;
    printf("%.2lf\n", getCrossRectangleArea(rect1, rect2));
    return 0;
}