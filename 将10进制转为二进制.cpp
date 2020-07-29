// 将10进制转为二进制
/*
如输入：13 输出：1101
*/
#include <stdio.h>
// int d2b(int n) // 这是一个递归函数
// {
//     if (n < 2) // 将这个函数里的三个2换成8，就可以将本函数改造为十进制转八进制函数
//         return n;
//     else
//     {
//         return d2b(n / 2) * 10 + n % 2;
//     }
// }
int d2b(int n) // 这是一个递归函数
{
    if (n < 8) // 将这个函数里的三个2换成8，就可以将本函数改造为十进制转八进制函数
        return n;
    else
    {
        return d2b(n / 8) * 10 + n % 8;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", d2b(n));
    return 0;
}
