// 回溯法
// 只能通过部分input
#include <iostream>
using namespace std;
const int MAX_n = 30;
// const int MAX_n = 30;
// const int MAX_m = 30;

int shortestPath[MAX_n + 1];
int oppositePos = 0;

inline int Next(int currentPos, int cycleSize)
{
    return currentPos == cycleSize ? 1 : currentPos + 1;
}

inline int Prev(int currentPos, int cycleSize)
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