// 李白打酒（递归）
/*
话说大诗人李白，一生好饮。幸好他从不开车。
一天，他提着酒壶，从家里出来，酒壶中有酒 2 斗。他边走边唱： 无事街上走，提壶去打酒。逢店加一倍，遇花喝一斗。
这一路上，他一共遇到店 5 次，遇到花 10 次，已知最后一次遇到的是花，他正好把酒喝光了。
请你计算李白遇到店和花的次序，可以把遇店记为a，遇花记为b。
则：babaabbabbabbbb 就是合理的次序。像这样的答案一共有多少呢？ 请你计算出所有可能方案的个数（包含题目给出的）。

输出：
bababaababbbbbb
babaabbabbabbbb
babaababbbbbabb 
baabbbaabbabbbb 
baabbabbbaabbbb 
baabbabbabbbabb 
baababbbbbababb 
abbbabaabbabbbb 
abbbaabbbaabbbb 
abbbaabbabbbabb
abbabbbabaabbbb 
abbabbbaabbbabb 
abbabbabbbababb 
ababbbbbabababb 
14
*/
#include <stdio.h>
int count = 0;  //可能方案的个数
char order[16]; //这一路上，他一共遇到店 5 次，遇到花 10 次。最后一个放'\0'
void fun(int num, int flower, int store, int remainingWine)
{
    // num：李白 已遇到花和店 的 次数
    // flower：李白遇到花的次数
    // store：李白遇到店的次数
    // remainingWine：酒壶中剩余的酒
    if (remainingWine < 0 || store > 5 || flower > 10)
    {
        return;
    }
    else if (num == 13 && store == 5 && remainingWine == 2)
    {
        count++;
        printf("%s\n", order);
        return;
    }
    else if (num < 13) //先遇花，先遇店结果都是一样，顺序相反
    {
        order[num] = 'b'; //遇到花
        fun(num + 1, flower + 1, store, remainingWine - 1);
        order[num] = 'a'; //遇到店
        fun(num + 1, flower, store + 1, remainingWine * 2);
    }
}
int main()
{
    // 由题知，李白最后两次遇到的必定是花，且第13次操作后酒壶中还剩酒2斗
    order[15] = '\0';
    order[14] = 'b';
    order[13] = 'b';
    fun(0, 0, 0, 2);
    printf("%d\n", count);
    return 0;
}

// 李白打酒（二进制求解）
// #include <stdio.h>
// int main()
// {
//     char order[16];
//     order[15] = '\0';
//     int remainingWine; //酒的斗数
//     int counta; //遇到店的次数
//     int countb; //遇到花的次数
//     int count = 0; //满足条件的方案的个数
//     int num;
//     for (int i = 31; i <= 7936; i++) //用二进制位表示可能的遇到花与店的情况
//     // parseInt(31).toString(2)
//     // 11111    相当于下面这个数
//     // 0000000011111
//     // parseInt(7936).toString(2)
//     // 1111100000000
//     {
//         order[14] = 'b';
//         order[13] = 'b';
//         remainingWine = 2;
//         counta = 0;
//         countb = 0;
//         num = i;
//         for (int j = 1; j <= 13; j++)
//         {
//             if (num % 2 == 0) //遇到的是花
//             {
//                 remainingWine = remainingWine - 1;
//                 order[j] = 'b';
//                 counta++;
//                 if (counta > 8)
//                 {
//                     break;
//                 }
//             }
//             else //遇到的是店
//             {
//                 remainingWine = remainingWine * 2;
//                 order[j] = 'a';
//                 countb++;
//                 if (countb > 5)
//                 {
//                     break;
//                 }
//             }
//             num = num / 2;
//         }
//         if (countb == 5 && remainingWine == 2)
//         {
//             count++;
//             printf("%s\n", order);
//         }
//     }
//     printf("%d\n", count);
//     return 0;
// }