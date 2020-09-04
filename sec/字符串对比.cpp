// 字符串对比
// AC
/*
问题描述
给定两个仅由大写字母或小写字母组成的字符串(长度介于 1 到 10 之间)，它们之间的关系是以下 4 种情况之一：
1：两个字符串长度不等。比如 Beijing 和 Hebei
2：两个字符串不仅长度相等，而且相应位置上的字符完全一致(区分大小写)，比如 Beijing 和 Beijing
3：两个字符串长度相等，相应位置上的字符仅在不区分大小写的前提下才能达到完全一致（也就是说，它并不满足情况 2）。比如 beijing 和 BEIjing
4：两个字符串长度相等，但是即使是不区分大小写也不能使这两个字符串一致。比 如 Beijing 和 Nanjing

编程判断输入的两个字符串之间的关系属于这四类中的哪一类，给出所属的类的编号。

输入格式
包括两行，每行都是一个字符串
输出格式
仅有一个数字，表明这两个字符串的关系编号

样例输入
BEIjing beiJing
样例输出
3
*/

// #include <stdio.h> // AC
// #include <string.h>
// int main()
// {
//     char a[11], b[11]; // 注意：a、b数组的长度应该为10+1==11
//     scanf("%s%s", a, b);

//     if (strlen(a) != strlen(b))
//         printf("1");
//     else if (strcmp(a, b) == 0)
//         printf("2");
//     // else if (strcasecmp(a, b) == 0) // AC
//     else if (stricmp(a, b) == 0) // AC
//         printf("3");
//     else
//         printf("4");
//     return 0;
// }

// strcasecmp函数用于比较字符串，比较时会自动忽略大小写的差异。
// 此函数只在Linux中提供，相当于windows平台的stricmp。

#include <iostream> // AC
#include <string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int lena = a.length();
    int lenb = b.length();
    if (lena != lenb)
    {
        cout << 1;
        return 0;
    }
    bool flag = true;
    for (int i = 0; i < lena; i++)
    {
        if (a[i] != b[i])
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
    {
        cout << 2;
        return 0;
    }
    bool flag2 = true;
    for (int i = 0; i < lena; i++)
    {
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
        if (a[i] != b[i])
        {
            flag2 = false;
            break;
        }
    }
    if (flag2 == true)
    {
        cout << 3;
    }
    else
    {
        cout << 4;
    }
    return 0;
}