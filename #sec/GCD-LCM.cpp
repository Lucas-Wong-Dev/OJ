// 输入两个数，求这两个数的最大公约数，及最小公倍数
/*
输入：9 27
输出：
最大公约数:9
最小公倍数:27
*/
/*
最大公约数
- 也称最大公因子、最大公因数 // 注意约数又称因数
- 英文名：Greatest Common Divisor(GCD) 或 Highest Common Factor(HCF)
- 两个或多个整数共有约数中最大的一个
- a，b的最大公约数记为（a，b），同样的，a，b，c的最大公约数记为（a，b，c），多个整数的最大公约数也有同样的记号
- 求最大公约数有多种方法，常见的有质因数分解法、短除法、辗转相除法、更相减损法

最小公倍数
- 英文名：Least Common Multiple(LCM)
- 两个或多个整数公有的倍数叫做它们的公倍数，其中除0以外最小的一个公倍数就叫做这几个整数的最小公倍数
- 整数a，b的最小公倍数记为[a，b]，同样的，a，b，c的最小公倍数记为[a，b，c]，多个整数的最小公倍数也有同样的记号。

关于最小公倍数与最大公约数，我们有这样的定理：(a,b)x[a,b]=ab(a,b均为整数)
即最小公倍数=两整数的乘积÷最大公约数
*/

// 求最大公约数（GCD）的3种算法
// way1 辗转相除法（while循环版）
/*
有两整数a和b：
① a%b 得余数r
② 若r==0，则b即为两数的最大公约数
③ 若r!=0，则令a=b，b=r，(即：令被除数等于除数，除数等于余数)再回去执行①，直到b==0，这时a即为最大公约数（因为在退出循环前，已经令被除数等于除数，除数等于余数，所以要判断余数是否为0，就要判断b是否为0）
例如求15和27的最大公约数过程为：
15÷27 余 15
27÷15 余 12
15÷12 余 3
12÷3  余 0
因此，3即为最大公约数，最小公倍数为15*27/3=135
*/
// 辗转相除法（while循环版）
#include <stdio.h>
// int getGCD(int a, int b) // AC 更好的写法（语义更清晰）
// {
//     int r = a % b;
//     while (r != 0)
//     {
//         a = b;
//         b = r;
//         r = a % b;
//     }
//     return b;
// }
// int getGCD(int a, int b) // AC
// {
//     int r; // remainder n. 余数
//     while (b != 0)
//     {
//         r = a % b;
//         a = b;
//         b = r;
//     }
//     return a;
// }
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int gcd = getGCD(a, b);

    printf("%d\n", gcd);         // 最大公约数
    printf("%d\n", a * b / gcd); // 最小公倍数
    return 0;
}
// 辗转相除法（递归版）：本质上是辗转相除法，只是实现形式上是递归，而不是while循环
// #include <stdio.h>

// int getGCD(int p, int q)
// {
//     return q == 0 ? p : getGCD(q, p % q);
// }

// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);

//     int gcd = getGCD(a, b);

//     printf("%d\n", gcd);
//     printf("%d\n", a * b / gcd);
//     return 0;
// }

// way2 相减法
/*
有两整数a和b：
① 若a>b，则a=a-b
② 若a<b，则b=b-a
③ 若a==b，则a（或b）即为两数的最大公约数；若a!=b，则再回去执行①
例如求 27 和 15 的最大公约数过程为：
a 27－15＝12  ( 15>12 )
b 15－12＝3   ( 12>3 )
a 12－3＝9    ( 9>3 )
a 9－3＝6     ( 6>3 )
a 6－3＝3     ( 3==3 )
因此，3 即为最大公约数
*/
// #include <stdio.h>
// int getGCD(int a, int b)
// {
//     while (a != b)
//     {
//         if (a > b)
//             a -= b;
//         else
//             b -= a;
//     }
//     return a; // 这里返回a或b都可以
// }
// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);

//     int gcd = getGCD(a, b);

//     printf("%d\n", gcd);
//     printf("%d\n", a * b / gcd);
//     return 0;
// }

// way3 穷举法
/*
有两整数a和b：
① i=1
② 若a，b均能被i整除，则gcd＝i
③ i++
④ 若i<= a(或b)，则再回去执行②；若i>a(或b)，则gcd即为最大公约数

改进：
① i=a(或b)
② 若a，b能同时被i整除，则i即为最大公约数，结束
③ i--，再回去执行②
*/
// #include <stdio.h>
// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     int gcd = -1;

//     int min = a < b ? a : b;
//     for (int i = 1; i <= min; i++)
//     {
//         if (a % i == 0 && b % i == 0)
//             gcd = i;
//     }

//     printf("%d\n", gcd);
//     printf("%d\n", a * b / gcd);
//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     int gcd = -1;

//     int min = a < b ? a : b;
//     for (int i = min; i >= 1; i--)
//     {
//         if (a % i == 0 && b % i == 0)
//         {
//             gcd = i;
//             break; // ★
//         }
//     }

//     printf("%d\n", gcd);
//     printf("%d\n", a * b / gcd);
//     return 0;
// }