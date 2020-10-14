// 串复制
/*
【C/C++组代码填空】
下列代码把一个串 p 复制到新的位置 q。请填写缺少的语句；
char* p = "abcde";
char* q = (char*)malloc(strlen(p)+1); 
for(int i=0;____; i++) 
    q[i] = p[i];
q[i] = 0;
【参考答案】
p[i] 或 *(p+i) 或 p[i] != '\0' 或 ...
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *p = "abcde";
    char *q = (char *)malloc(strlen(p) + 1);
    int i;
    // ----------------------1
    // for (i = 0; p[i]; i++)
    //     q[i] = p[i];

    // ----------------------2
    // for (i = 0; *(p + i); i++)
    //     q[i] = p[i];

    // ----------------------3
    for (i = 0; p[i] != '\0'; i++)
        q[i] = p[i];

    // ----------------------4
    for (i = 0; p[i] != 0; i++)
        q[i] = p[i];
    q[i] = 0;

    printf("%s\n", p);
    printf("%s\n", q);
    return 0;
}