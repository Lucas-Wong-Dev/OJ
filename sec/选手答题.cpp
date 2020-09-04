// 选手答题
/*
某电视台举办了低碳生活大奖赛。题目的计分规则相当奇怪：
每位选手需要回答10个问题（其编号为 1 到 10），越后面越有难度。答对的，当前分数翻倍；答错了则扣掉与题号相同的分数（选手必须回答问题，不回答按错误处理）。
每位选手都有一个起步的分数为 10 分。
某获胜选手最终得分刚好是 100 分，如果不让你看比赛过程， 你能推断出他（她）哪个题目答对了，哪个题目答错了吗？
如果把答对的记为 1，答错的记为 0，则 10 个题目的回答情况可以用仅含有 1 和 0 的串来表示。
例如：0010110011 就是可能的情况。
你的任务是算出所有可能情况。每个答案占一行。

输出：
1011010000
0111010000
0010110011
*/

#include <stdio.h>
char a[10 + 1];
void fact(int n, int currentScore) // 在执行函数内的语句前，该选手的得分为currentScore，需要回答第n题
{
    if (n == 11 && currentScore != 100)
    {
        return;
    }
    if (n == 11 && currentScore == 100)
    {
        for (int i = 1; i <= 10; i++)
        {
            printf("%c", a[i]);
        }
        printf("\n");
        return;
    }
    a[n] = '1';
    fact(n + 1, currentScore * 2); // 答对的，当前分数翻倍
    a[n] = '0';
    fact(n + 1, currentScore - n); // 答错了则扣掉与题号相同的分数
}
int main()
{
    int n = 1, currentScore = 10;
    fact(n, currentScore);
    return 0;
}