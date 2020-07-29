/* FJ的字符串
问题描述
FJ在沙盘上写了这样⼀些字符串：
A1 = “A”
A2 = “ABA”
A3 = “ABACABA”
A4 = “ABACABADABACABA”
……
你能找出其中的规律并写所有的数列AN吗？

输⼊格式
仅有⼀个数：N ≤ 26。

输出格式
请输出相应的字符串AN，以⼀个换⾏符结束。输出中不得含有多余的空格或换⾏、回⻋符。

样例输⼊
3

样例输出
ABACABA
*/

#include <iostream>
using namespace std;

string dfs(int n)
{
    if (n == 1)
    {
        return "A";
    }
    else
    {
        return dfs(n - 1) + (char)(n + 'A' - 1) + dfs(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << dfs(n);
    return 0;
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     int n;
//     char str[1024] = "A", strTemp[1024];
//     scanf("%d", &n);
//     for (int i = 1; i < n; i++) //注意：对A1进行一次处理即可得到A2，再对A2进行一次处理即可得到A3，也就是说为了得到A3，我们要进行两次变换。每次循环期间都进行了一次处理，因此这里循环结束条件为i<n
//     {
//         sprintf(strTemp, "%s%c%s", str, 'A' + i, str); //用于发送格式化输出到strTemp所指向的字符串
//         strcpy(str, strTemp);// 将strTemp复制到str中
//     }
//     printf("%s", str);
//     return 0;
// }

/*
sprintf()
位于<stdio.h>
用于发送格式化输出到str所指向的字符串
函数原型：int sprintf(char *str, const char *format, ...)
返回值:如果成功，则返回写入的字符总数，不包括追加在字符串末尾的空字符。如果失败，则返回一个负数。
参数：
    str -- 这是指向一个字符数组的指针，该数组存储了C字符串
    format -- 这是字符串，包含了要被写入到字符串str的文本。它可以包含嵌入的format标签，format标签可被随后的附加参数中指定的值替换，并按需求进行格式化。format标签属性是%[flags][width][.precision][length]specifier，具体见后面
    附加参数 -- 根据不同的 format 字符串，函数可能需要一系列的附加参数，每个参数包含了一个要被插入的值，替换了format参数中指定的每个%标签

flags（标识）   描述
-   在给定的字段宽度内左对齐，默认是右对齐
+   强制在结果之前显示加号或减号（+ 或 -），即正数前面会显示+号。默认情况下，只有负数前面会显示一个-号。

width（宽度）描述
(number)    要输出的字符的最小数目。如果输出的值短于该数，结果会用空格填充。如果输出的值长于该数，结果不会被截断。

length（长度）	描述
h	参数被解释为短整型或无符号短整型，仅适用于整数说明符：i、d、o、u、x 和 X。
l	参数被解释为长整型或无符号长整型，适用于整数说明符（i、d、o、u、x 和 X）及说明符c（表示一个宽字符）和s（表示宽字符字符串）。
L	参数被解释为长双精度型，仅适用于浮点数说明符：e、E、f、g 和 G。

specifier（说明符）  输出
c                   字符
d                   有符号十进制整数
s                   字符串
*/