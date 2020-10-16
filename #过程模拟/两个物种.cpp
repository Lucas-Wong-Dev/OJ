// 两个物种
/*
假设有两种微生物X和Y
X出生后每隔3分钟分裂一次（数目加倍），Y出生后每隔2分钟分裂一次（数目加倍）。
一个新出生的X，半分钟之后吃掉1个Y，并且，从此开始，每隔1分钟吃1个Y。
现在已知有新出生的X=10, Y=89，求60分钟后Y的数目。
如果X=10，Y=90呢？
本题的要求就是写出这两种初始条件下，60分钟后Y的数目。
题目的结果令你震惊吗？这不是简单的数字游戏！真实的生物圈有着同样脆弱的性质！也许因为你消灭的那只Y就是最终导致Y种群灭绝的最后一根稻草！
请忍住悲伤，把答案写在“解答.txt”中，不要写在这里！
答案：
  94371840   （1.5分）
  0          （1.5分）
*/
// X=10,Y=90时，输出：94371840
// X=10,Y=89时，输出：0

#include <stdio.h>
void fun(long long *pNumOfX, long long *pNumOfY)
{
    for (int i = 0; i < 120; i++) // i++意味着时间过去了半分钟
    {
        if (i % 2 == 1) // 一个新出生的X，半分钟之后吃掉1个Y，并且，从此开始，每隔1分钟吃1个Y。所以只当奇数个半分钟时，X才会吃Y。又因为当奇数个半分钟时X不会增长，所以直接把numOfY减去numOfX即可
        {
            *pNumOfY -= *pNumOfX;
            if (*pNumOfY <= 0)
            {
                *pNumOfY = 0;
                break;
            }
        }
        if (i % 4 == 0) // Y出生后每隔2分钟分裂一次（数目加倍）
            *pNumOfY *= 2;
        if (i % 6 == 0) // X出生后每隔3分钟分裂一次（数目加倍）
            *pNumOfX *= 2;
    }
}
int main()
{
    long long numOfX = 10, numOfY = 90;
    long long *pNumOfX = &numOfX, *pNumOfY = &numOfY;
    fun(pNumOfX, pNumOfY);
    printf("%d %d\n", numOfX, numOfY);

    numOfX = 10, numOfY = 89;
    fun(pNumOfX, pNumOfY);
    printf("%d %d\n", numOfX, numOfY);

    return 0;
}