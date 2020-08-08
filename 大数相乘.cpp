// 大数相乘
//输入两个数，输出两个数的相乘结果
/*
输出：
1082152022374638
*/
#include <stdio.h>
void bigmul(int x, int y, int r[])
{
    printf("bigmul\n");
    int base = 10000;
    int x2 = x / base;
    int x1 = x % base; // x的低4位
    int y2 = y / base;
    int y1 = y % base; // y的低4位

    int n1 = x1 * y1;
    int n2 = x1 * y2;
    int n3 = x2 * y1;
    int n4 = x2 * y2;

    r[3] = n1 % base;
    r[2] = n1 / base + n2 % base + n3 % base;
    r[1] = n3 / base + n2 / base + n4 % base;
    r[0] = n4 / base;

    printf("%d %d %d %d\n", r[0], r[1], r[2], r[3]);
    r[1] += r[2] / base;
    printf("%d %d %d %d\n", r[0], r[1], r[2], r[3]);
    r[2] = r[2] % base;
    printf("%d %d %d %d\n", r[0], r[1], r[2], r[3]);
    r[0] += r[1] / base;
    printf("%d %d %d %d\n", r[0], r[1], r[2], r[3]);
    r[1] = r[1] % base;
    printf("%d %d %d %d\n", r[0], r[1], r[2], r[3]);
}

int main()
{
    int x[] = {0, 0, 0, 0};
    bigmul(87654321, 12345678, x);
    printf("%d%d%d%d\n", x[0], x[1], x[2], x[3]);
    return 0;
}