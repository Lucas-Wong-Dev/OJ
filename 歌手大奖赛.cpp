// 歌手大奖赛
/*
在歌星大奖赛中，有 10 个评委为参赛的选手打分，分数为 1~100 分。选手最后得分为：去掉一个最高分和一个最低分后,其余8个分数的平均值。请编写一个程序实现。题目条件不变，但考虑同时对评委评分进行裁判，即在 10 个评委中找出最公平和最不公平…
在歌星大奖赛中，有 10 个评委为参赛的选手打分，分数为 1~100 分。选手最后得分为：去掉一个最高分和一个最低分后其余 8 个分数的平均值。请编写一个程序实现。

输入：
Input number1=90
Input number2=91 
Input number3=93 
Input number4=94 
Input number5=90 
Input number6=99 
Input number7=97 
Input number8=92 
Input number9=91 
Input number10=95

输出：
Canceled max score:99
Canceled min score:90 
Average score:92
*/
#include <stdio.h>
int main(void)
{
    int integer, max, min, sum;
    max = -32768;
    min = 32767;
    sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        printf("Input number %d=", i);
        scanf("%d", &integer);
        sum += integer;
        if (integer > max)
            max = integer;
        if (integer < min)
            min = integer;
    }
    printf("Canceled max score:%d\nCanceled min score:%d\n", max, min);
    printf("Average score:%d\n", (sum - max - min) / 8);
    return 0;
}

// #include <stdio.h>
// #include <limits.h>
// int main()
// {
//     printf("The value of INT_MAX is %i\n", INT_MAX);
//     printf("The value of INT_MIN is %i\n", INT_MIN);
//     printf("An int takes %d bytes\n", sizeof(int));
//     return 0;
// }


// C 语言的 int 类型变量范围是多少？

// c标准里面只定义了int的最小宽度，所以这个范围就完全依赖于编译器的实现了。请看c99的 5.2.4.2.1
// Their implementation-defined values shall be equal or greater in magnitude (absolute value) to those shown, with the same sign.   
// minimum value for an object of type int
// INT_MIN -32767 // -(2^15 - 1)

// https://www.zhihu.com/question/19580654