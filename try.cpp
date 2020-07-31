#include <stdio.h>
int main()
{
    int m, n, a, b, i, t = 0;
    scanf("%d,%d", &a, &b);
    m = a;
    n = b;
    for (i = 1; i <= a; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            t = i;
        }
    }
    printf("The largest common divisor:%d\n", t);
    printf("The least common multiple:%d\n", m * n / t);
}
// 改进后的
// for (t = a; t > 0; t--)
//     if (a % t == 0 && b % t == 0)
//         break;
