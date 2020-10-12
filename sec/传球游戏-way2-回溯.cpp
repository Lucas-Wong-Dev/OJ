// 回溯法
// 这两份代码都只能通过部分input
// #include <stdio.h>
// #include <math.h>
// const int MAX_n = 30;
// const int MAX_m = 30;
// long long sum = 0;

// void fun(int curP, int n, int m)
// {
//     // printf("curP==%d n==%d m==%d\n", curP, n, m);
//     if (m == 0)
//     {
//         if (curP == 1)
//         {
//             sum++;
//         }
//         // printf("--> sum==%d m==%d curP=%d\n", sum, m, curP);
//         return;
//     }

//     if (curP - m > 1 && curP + m <= n)
//     {
//         return;
//     }
//     else if (curP - m == 1 && curP + m == n + 1)
//     {
//         sum += 2;
//         return;
//     }

//     if (curP + 1 == n + 1)
//     {
//         fun(1, n, m - 1);
//     }
//     else
//     {
//         fun(curP + 1, n, m - 1);
//     }

//     if (curP - 1 == 0)
//     {
//         fun(n, n, m - 1);
//     }
//     else
//     {
//         fun(curP - 1, n, m - 1);
//     }
// }

// int main()
// {
//     int n, m;
//     scanf("%d%d", &n, &m);
//     fun(1, n, m);
//     // printf("%d\t%d\t%lld\n", n, m, sum);
//     printf("%lld\n", sum);

//     // int n, m;
//     // for (n = 0; n <= MAX_n; n++)
//     // {
//     //     for (m = 0; m <= MAX_m; m++)
//     //     {
//     //         fun(1, n, m);
//     //         printf("%d\t%d\t%lld\n", n, m, sum);
//     //         sum = 0;
//     //     }
//     // }

//     return 0;
// }

#include <iostream>
using namespace std;
const int MAX_n = 30;
// const int MAX_n = 30;
// const int MAX_m = 30;

int shortestPath[MAX_n + 1];
int oppositePos = 0;

inline int Next(int currentPos, int cycleSize)
// int Next(int currentPos, int cycleSize)
{
    return currentPos == cycleSize ? 1 : currentPos + 1;
}

inline int Prev(int currentPos, int cycleSize)
// int Prev(int currentPos, int cycleSize)
{
    return currentPos == 1 ? cycleSize : currentPos - 1;
}

void CalcShortestPath(int cycleSize)
{
    if (cycleSize % 2 == 0)
    {
        oppositePos = cycleSize / 2 + 1;
    }
    shortestPath[0] = shortestPath[1] = 0;
    for (int i = 2, j = cycleSize, s = 1; i <= j; i++, j--, s++)
    {
        shortestPath[i] = shortestPath[j] = s;
    }
}

int Search(int currentPos, int cycleSize, int stepLeft)
{
    if (shortestPath[currentPos] > stepLeft)
    {
        return 0;
    }

    if (shortestPath[currentPos] == stepLeft)
    {
        return currentPos == oppositePos ? 2 : 1;
    }

    return Search(Next(currentPos, cycleSize), cycleSize, stepLeft - 1) +
           Search(Prev(currentPos, cycleSize), cycleSize, stepLeft - 1);
}

int main()
{
    int cycleSize, stepLeft;
    cin >> cycleSize >> stepLeft;
    CalcShortestPath(cycleSize);
    cout << Search(1, cycleSize, stepLeft) << endl;
}