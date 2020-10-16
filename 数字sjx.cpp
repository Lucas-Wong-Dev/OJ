#include <iostream>
using namespace std;
const int MAX_N = 100;
int main()
{
    int N;
    cin >> N;
    int D[MAX_N + 1][MAX_N + 1] = {0};
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> D[i][j];
        }
    }

    int maxSum[MAX_N + 1][MAX_N + 1] = {0};
    for (int j = 1; j <= N; j++)
    {
        maxSum[N][j] = D[N][j];
    }

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            maxSum[i][j] = max(maxSum[i + 1][j], maxSum[i + 1][j + 1]) + D[i][j];
        }
    }

    cout << maxSum[1][1] << endl;

    return 0;
}