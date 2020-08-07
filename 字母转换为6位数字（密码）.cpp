// 字母转换为6位数字（密码）
/*
这个程序的任务就是把一串拼音字母转换为 6 位数字（密码）。我们可以使用任何好记的拼音串(比如名字，王喜明，就写：wangximing)作为输入，程序输出6位数字。变换的过程如下： 

第一步. 把字符串 6 个一组折叠起来，比如wangximing 则变为：
wangxi ming
第二步. 把所有垂直在同一个位置的字符的 ascii 码值相加，得出 6 个数字，如上面的例子，则得出：228 202 220 206 120 105
第三步. 再把每个数字“缩位”处理：就是把每个位的数字相加，得出的数字如果不是一位数字，就再缩位，直到变成一位数字为止。例如: 228 => 2+2+8=12 => 1+2=3
上面的数字缩位后变为：344836, 这就是程序最终的输出结果！ 要求程序从标准输入接收数据，在标准输出上输出结果。

输入格式为：第一行是一个整数n（<100），表示下边有多少输入行，接下来是n行字符串，就是等待变换的字符串。

输出格式为：n 行变换后的6位密码。如： 
输入：
1
xuyisu
输出：
3	9	4	6	7	9
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int str[6], istr;
// 第一步. 把字符串 6 个一组折叠起来，比如wangximing 则变为：/wangxi ming
// 第二步. 把所有垂直在同一个位置的字符的 ascii 码值相加，得出 6个数字，如上面的例子，则得出：228 202 220 206 120 105
void getstr()
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        str[istr % 6] += ch; //把所有垂直在同一个位置的字符的 ascii 码值相加
        istr++;
    }
}
// 第三步. 再把每个数字“缩位”处理：就是把每个位的数字相加，得出的数字如果不是一位数字，就再缩位，直到变成一位数字为止。例如: 228 => 2+2+8=12 => 1+2=3
void cal()
{
    for (int i = 0; i < 6; i++)
    {
        while (str[i] > 9)
        {
            int temp = str[i];
            str[i] = 0;
            while (temp)
            {
                str[i] += temp % 10;
                temp /= 10;
            }
        }
    }
}
void save(int ans[][6], int * numOfAns) //将结果保存入数组
{
    for (int i = 0; i < 6; i++)
        ans[*numOfAns][i] = str[i];
    (*numOfAns)++;
}
int main()
{
    int n;
    scanf("%d", &n);
    int ans[99][6], numOfAns = 0;

    getchar();
    while (n--)
    {
        memset(str, 0, sizeof(str));
        istr = 0;
        getstr();
        cal();
        save(ans, &numOfAns);
    }

    for (int i = 0; i < numOfAns; i++) //输出结果
    {
        for (int j = 0; j < 6; j++)
            printf("%d\t", ans[i][j]);
        printf("\n");
    }
    return 0;
}
