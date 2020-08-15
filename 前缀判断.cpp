// 前缀判断
/*
前缀判断
如下的代码判断 needle_start 指向的串是否为 haystack_start 指向的串的前缀，

如不是， 则返回NULL。
比如："abcd1234" 就包含了 "abc" 为前缀
输出： 是
*/
#include <stdio.h>
char *prefix(char *needle_start, char *haystack_start)
{
    while (*haystack_start && *needle_start)
    {
        if (*(needle_start++) != *(haystack_start++))
            return NULL;
    }
    if (!needle_start)
        return NULL;
    return haystack_start;
}
int main()
{
    char needle_start[100] = {"abc"};
    char haystack_start[100] = {"abc123"};
    if (prefix(needle_start, haystack_start))
        // printf("是\n");
        printf("1\n");
    else
        // printf("否\n");
        printf("0\n");

    return 0;
}
