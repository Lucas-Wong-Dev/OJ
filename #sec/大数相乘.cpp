// 大数相乘
#include <stdio.h>
void bigmul(int x, int y, int r[])
{
    int base = 10000;

    int x2 = x / base;
    int x1 = x % base; // x的低4位
    int y2 = y / base;
    int y1 = y % base; // y的低4位

    int m1 = x1 * y1;
    int m2 = x2 * y1;
    int m3 = x1 * y2;
    int m4 = x2 * y2;

    r[4] = m1 % base;
    r[3] = m1 / base + m2 % base + m3 % base;
    r[2] = m2 / base + m3 / base + m4 % base;
    r[1] = m4 / base;
	
    // printf("%d %d %d %d\n", r[1], r[2], r[3], r[4]);
    r[2] += r[3] / base; // 小块在进行纵向累加后，需要进行进位校正
    // printf("%d %d %d %d\n", r[1], r[2], r[3], r[4]);
    r[3] = r[3] % base;
    // printf("%d %d %d %d\n", r[1], r[2], r[3], r[4]);
    r[1] += r[2] / base;
    // printf("%d %d %d %d\n", r[1], r[2], r[3], r[4]);
    r[2] = r[2] % base;
    // printf("%d %d %d %d\n", r[1], r[2], r[3], r[4]);
}

int main()
{
    int r[4 + 1] = {0};
    long long a = 99999999;
    long long b = 99999999;
    bigmul(a, b, r);
    printf("%04d%04d%04d%04d\n", r[1], r[2], r[3], r[4]);
    printf("%lld\n", a * b);

    return 0;
}