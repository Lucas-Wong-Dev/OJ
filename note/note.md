# note

闰年共366天，其二月份有29天
平年共365天，其二月份有28天

数位分离的题

```cpp
#include <stdio.h>
#include <math.h>
const int MAX_w = 9;
int main()
{
    int w = 0;
    scanf("%d", &w);
    while (w > MAX_w) // 输入位数
    {
        printf("error! MAX_w == %d\n", MAX_w);
        scanf("%d", &w);
    }

    int num = 0;
    for (int i = 1; i <= w; i++) // 构建num
    {
        num += (i * pow(10, i - 1));
    }
    printf("%d\n", num); // 输出构建出来的数字

    int a[MAX_w] = {0};
    for (int i = 1; i <= w; i++) // 数位分离
    {
        // a[i] = (num % (int)pow(10, i)) / (int)pow(10, i - 1); // right
        a[i] = (num / (int)pow(10, i - 1)) % 10; // right
    }

    // 可见，数位分离有两种方法
    // way1：先用%分离出num的后i位数字，再用/得到新数字的首位
    // way2：先用/删掉第i位后面的数字，再用%得到新数字的末位

    for (int i = w; i >= 1; i--) // 输出分离出来的各位数字
    {
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}
```



```cpp
/*
sprintf()
位于<stdio.h>
函数原型：int sprintf(char *str, const char *format, ...)
用于发送格式化输出到str所指向的字符串
返回值：如果成功，则返回写入的字符总数，不包括追加在字符串末尾的空字符。如果失败，则返回一个负数。
参数：
    str -- 这是指向一个字符数组的指针，该数组存储了C字符串
    format -- 这是字符串，包含了要被写入到字符串str的文本。它可以包含嵌入的format标签，format标签可被随后的附加参数中指定的值替换，并按需求进行格式化。format标签属性是%[flags][width][.precision][length]specifier，具体见后面
    附加参数 -- 根据不同的format字符串，函数可能需要一系列的附加参数，每个参数包含了一个要被插入的值，替换了format参数中指定的每个%标签

flags（标识）   描述
-   在给定的字段宽度内左对齐，默认是右对齐
+   强制在结果之前显示加号或减号（+ 或 -），即正数前面会显示+号。默认情况下，只有负数前面会显示一个-号。

width（宽度）描述
(number)    要输出的字符的最小数目。如果输出的值短于该数，结果会用空格填充。如果输出的值长于该数，结果不会被截断。

length（长度）	描述
h	参数被解释为 短整型 或 无符号短整型 ，仅适用于整数说明符：i、d、o、u、x 和 X。
l	参数被解释为 长整型 或 无符号长整型 ，适用于整数说明符（i、d、o、u、x 和 X）及说明符c（表示一个宽字符）和s（表示宽字符字符串）。
L	参数被解释为 长双精度型 ，仅适用于浮点数说明符：e、E、f、g 和 G。

specifier（说明符）  输出
c                   字符
d                   有符号十进制整数
s                   字符串
*/
```

