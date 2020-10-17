// 12-1三角形
// AC
// http://lx.lanqiao.cn/problem.page?gpid=T415
/*
问题描述
为二维空间中的点设计一个结构体，在此基础上为三角形设计一个结构体。分别设计独立的函数计算三角形的周长、面积、外心和重心。

输入三个点，输出这三个点构成的三角形的周长、面积、外心和重心。
结果保留小数点后2位数字。

数据规模和约定
输入数据中每一个数的范围。
例：doule型表示数据。
*/
/* 
仅当三角形是等边三角形时，重心、垂心、内心、外心四心合一心，称做正三角形的中心

重心：三条中线的交点。重心到 顶点 的距离是 它到该顶点对边的中点距离 的2倍
centre of gravity

垂心：三角形三条高线的交点
orthocenter

内心：三条角平分线的交点，是三角形的内切圆的圆心的简称。内心到三边的距离相等
incenter

外心：三条中垂线的交点，是三角形的外接圆的圆心的简称。外心到各顶点的距离相等
circumcenter
*/
#include <stdio.h>
#include <math.h>
typedef struct dot
{
    double x, y;
} DOT;
// triangle n. 三角（形）
typedef struct triangle
{
    DOT dot1;
    DOT dot2;
    DOT dot3;
} TRIANGLE;

double getDistance(DOT a, DOT b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// perimeter n. 周长
double getPerimeter(TRIANGLE tri)
{
    double side1 = getDistance(tri.dot1, tri.dot2);
    double side2 = getDistance(tri.dot2, tri.dot3);
    double side3 = getDistance(tri.dot1, tri.dot3);
    return side1 + side2 + side3;
}

double getArea(TRIANGLE tri)
{
    double side1 = getDistance(tri.dot1, tri.dot2);
    double side2 = getDistance(tri.dot2, tri.dot3);
    double side3 = getDistance(tri.dot1, tri.dot3);
    double p = getPerimeter(tri) / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

DOT getCircumcenter(TRIANGLE tri) // 外心
{
    DOT dot1 = tri.dot1;
    DOT dot2 = tri.dot2;
    DOT dot3 = tri.dot3;

    double A1 = 2 * (dot1.x - dot2.x);
    double B1 = 2 * (dot1.y - dot2.y);
    double C1 = dot1.x * dot1.x + dot1.y * dot1.y - dot2.x * dot2.x - dot2.y * dot2.y;

    double A2 = 2 * (dot3.x - dot2.x);
    double B2 = 2 * (dot3.y - dot2.y);
    double C2 = dot3.x * dot3.x + dot3.y * dot3.y - dot2.x * dot2.x - dot2.y * dot2.y;

    DOT circumcenter;
    circumcenter.x = ((C1 * B2) - (C2 * B1)) / ((A1 * B2) - (A2 * B1));
    circumcenter.y = ((A1 * C2) - (A2 * C1)) / ((A1 * B2) - (A2 * B1));
    return circumcenter;
}

DOT getGravityCenter(TRIANGLE tri) // 重心 ★
{
    DOT dot1 = tri.dot1;
    DOT dot2 = tri.dot2;
    DOT dot3 = tri.dot3;
    DOT gravityCenter;
    gravityCenter.x = (dot1.x + dot2.x + dot3.x) / 3;
    gravityCenter.y = (dot1.y + dot2.y + dot3.y) / 3;
    return gravityCenter;
}

int main()
{
    TRIANGLE tri;
    scanf("%lf%lf", &tri.dot1.x, &tri.dot1.y);
    scanf("%lf%lf", &tri.dot2.x, &tri.dot2.y);
    scanf("%lf%lf", &tri.dot3.x, &tri.dot3.y);

    DOT circumcenter = getCircumcenter(tri);
    DOT gravityCenter = getGravityCenter(tri);

    printf("%.2lf\n", getPerimeter(tri));
    printf("%.2lf\n", getArea(tri));
    printf("%.2lf %.2lf\n", circumcenter.x, circumcenter.y);
    printf("%.2lf %.2lf\n", gravityCenter.x, gravityCenter.y);
}