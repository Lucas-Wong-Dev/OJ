// 第39台阶
/*
如果我每一步迈上 1 个或2个台阶，先迈左脚，然后左右交换，最后一步迈右脚， 也就是一共要走偶数步，
那么，上完 39 级台阶，有多少种不同的算法
*/
/*
思路：
不管走的是左脚还是右脚，只要走的步数是偶数即可
递归
39,0
38,1	37,1
37,2	36,2	36,2	35,2
...	...	...	...	...	...	...	...
输出：Total=51167078
*/

//方法1：从顶部算（better）
// #include <stdio.h>
// long sum = 0; //计数
// void count(int num, int step)
// {
//     if (num < 0)
//         return;
//     if (num == 0 && step % 2 == 0)
//     {
//         sum++;
//         return;
//     }
//     count(num - 1, step + 1);
//     count(num - 2, step + 1);
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     count(n, 0);
//     printf("%lld\n", sum);
//     return 0;
// }

//方法2：从底部算
#include <stdio.h> 
long long sum = 0; //计数
void count(int num, int step)
{
    if (num > 39)
        return;
    if (num == 39 && step % 2 == 0)
    {
        sum++;
        return;
    }
    count(num + 1, step + 1);
    count(num + 2, step + 1);
}

int main()
{
    count(0, 0); 
    printf("%lld", sum);
    return 0;
}