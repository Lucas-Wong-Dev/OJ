// AC
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100;
const int MAX_W = 10000;
int dp[MAX_N + 1][MAX_W + 1];
int select[MAX_N + 1];

void Knap(int N, int W, int *weight, int *value)
{
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 0;
    }
    for (int r = 0; r <= W; r++)
    {
        dp[0][r] = 0;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int r = 1; r <= W; r++)
        {
            if (r < weight[i])
            {
                dp[i][r] = dp[i - 1][r];
            }
            else
            {
                dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - weight[i]] + value[i]);
            }
        }
    }
}

int Buildx(int N, int W, int *weight, int *value, int *totalWeightOfLoadedObjects)
{
    int maxV = 0, i = N, r = W;
    while (i >= 1)
    {
        if (dp[i][r] == dp[i - 1][r])
        {
            select[i] = false;
        }
        else
        {
            select[i] = true;
            maxV += value[i];
            r -= weight[i];
        }
        i--;
    }
    *totalWeightOfLoadedObjects = W - r;
    return maxV;
}
int main()
{
    int N = 5, W = 10;
    int weight[MAX_N + 1] = {0, 2, 2, 6, 5, 4};
    int value[MAX_N + 1] = {0, 6, 3, 5, 4, 6};

    Knap(N, W, weight, value);
    int totalWeightOfLoadedObjects;
    int maxV = Buildx(N, W, weight, value, &totalWeightOfLoadedObjects);

    cout << totalWeightOfLoadedObjects << " " << maxV << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << select[i] << " ";
    }

    return 0;
}