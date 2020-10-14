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

