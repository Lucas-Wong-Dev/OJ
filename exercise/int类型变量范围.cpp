#include <stdio.h>
#include <limits.h>
int main()
{
    printf("The value of INT_MAX is %i\n", INT_MAX);
    printf("The value of INT_MIN is %i\n", INT_MIN);
    printf("An int takes %d bytes\n", sizeof(int));
    return 0;
}

// C 语言的int类型变量范围是多少？

// c标准里面只定义了int的最小宽度，所以这个范围就完全依赖于编译器的实现了。请看c99的 5.2.4.2.1
// Their implementation-defined values shall be equal or greater in magnitude (absolute value) to those shown, with the same sign.
// minimum value for an object of type int
// INT_MIN -32767 // -(2^15 - 1)

// https://www.zhihu.com/question/19580654