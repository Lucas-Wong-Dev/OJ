// 输入两个数，求这两个数的最大公约数，及最小公倍数（三种算法）
/*
输入：Enter a and b:9 27
输出：
最大公约数是:9
最小公倍数是:27
*/
// 方法一	辗转相除法
// #include <stdio.h>
// int main()
// {
//     int a, b, aTemp, bTemp, temp;
//     scanf("%d%d", &a, &b);
//     aTemp = a;
//     bTemp = b;
//     while (bTemp != 0)
//     {
//         temp = aTemp % bTemp;
//         aTemp = bTemp;
//         bTemp = temp;
//     }
//     printf("%d\n", aTemp); // 最大公约数
//     printf("%d\n", a * b / aTemp); // 最小公倍数
//     return 0;
// }

// 方法二 相减法
// #include <stdio.h>
// int main()
// {
//     int a, b, m, n;
//     scanf("%d%d", &a, &b);
//     m = a, n = b;
//     while (a != b)
//     {
//         if (a > b)
//             a -= b;
//         else
//             b -= a;
//     }
//     printf("最大公约数是:%d\n", a); //这里输出a或b都可以
//     printf("最小公倍数是:%d\n", m * n / a);
//     return 0;
// }

//方法三 穷举法
#include <stdio.h>
int main()
{
    int i = 1, a, b, t, m, n;
    scanf("%d%d", &a, &b);
    m = a;
    n = b;

    while (i <= a)
    {
        if (a % i == 0 && b % i == 0)
            t = i;
        i++;
    }

    // for (i = 1; i <= a; i++)
    //     if (a % i == 0 && b % i == 0)
    //         t = i;

    printf("%d\n", t);
    printf("%d\n", m * n / t);

    return 0;
}
