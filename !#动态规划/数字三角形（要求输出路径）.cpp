// 数字三角形（要求输出路径）
/*
要求
在数字三角形的基础上，还要输出该路径

首先输入N，
接下来的1～N行，第i行输入i个整数，

输出分为2行，
第一行为“最大/小和路径上的数字”，第2行为“从顶部到底部的最大/小和”
*/
/* 
状态转移方程
这里有两个边界，即第1列和对角线，达到它们中结点的路径只有一条而不是常规的两条
所以状态转移方程如下：
dp[1][1]=D[1][1] 顶部边界
dp[i][1]=dp[i-1][1]+D[i][1] 第1列的边界
dp[i][i]=dp[i-1][i-1]+D[i][i] 对角线的边界
dp[i][j]=max/min(dp[i-1][j-1], dp[i-1][j])+D[i][j] 其他有两条达到路径的结点
*/
#include <stdio.h>

const int MAX_N = 100; // 数字三角形的最大行数

int getMaxSum(int N, int D[][MAX_N + 1], int maxSum[][MAX_N + 1], int columnIndexOfPreNode[][MAX_N + 1], int *k) // AC 用这个函数测试了下数字三角形那题，成功AC了
{
    maxSum[1][1] = D[1][1]; // 根结点

    for (int i = 2; i <= N; i++) // 第1列上的结点
    {
        maxSum[i][1] = maxSum[i - 1][1] + D[i][1];
        columnIndexOfPreNode[i][1] = 1; // 结点D[i][1]的前驱结点只有结点D[i-1][1]
    }

    for (int i = 2; i <= N; i++) // 对角线上的结点
    {
        maxSum[i][i] = maxSum[i - 1][i - 1] + D[i][i];
        columnIndexOfPreNode[i][i] = i - 1; // 结点D[i][1]的前驱结点只有结点D[i-1][i-1]
    }

    for (int i = 3; i <= N; i++) // 其他有两个前驱结点的结点
    {
        for (int j = 2; j <= i - 1; j++)
        {
            if (maxSum[i - 1][j - 1] > maxSum[i - 1][j])
            {
                maxSum[i][j] = maxSum[i - 1][j - 1] + D[i][j];
                columnIndexOfPreNode[i][j] = j - 1;
            }
            else
            {
                maxSum[i][j] = maxSum[i - 1][j] + D[i][j];
                columnIndexOfPreNode[i][j] = j;
            }
        }
    }

    int sum = maxSum[N][1];      // sum为从顶部到底部的最大和
    int columnIndex = 1;         // 终点结点的列下标
    for (int j = 2; j <= N; j++) // 求出从顶部到底部的最大和、终点结点的列下标
    {
        if (maxSum[N][j] > sum)
        {
            sum = maxSum[N][j];
            columnIndex = j;
        }
    }
    *k = columnIndex;

    return sum;
}

int getMinSum(int N, int D[][MAX_N + 1], int minSum[][MAX_N + 1], int columnIndexOfPreNode[][MAX_N + 1], int *k)
{
    minSum[1][1] = D[1][1]; // 根结点

    for (int i = 2; i <= N; i++) // 第1列上的结点
    {
        minSum[i][1] = minSum[i - 1][1] + D[i][1];
        columnIndexOfPreNode[i][1] = 1; // 结点D[i][1]的前驱结点只有结点D[i-1][1]
    }

    for (int i = 2; i <= N; i++) // 对角线上的结点
    {
        minSum[i][i] = minSum[i - 1][i - 1] + D[i][i];
        columnIndexOfPreNode[i][i] = i - 1; // 结点D[i][1]的前驱结点只有结点D[i-1][i-1]
    }

    for (int i = 3; i <= N; i++) // 其他有两个前驱结点的结点
    {
        for (int j = 2; j <= i - 1; j++)
        {
            if (minSum[i - 1][j - 1] < minSum[i - 1][j])
            {
                minSum[i][j] = minSum[i - 1][j - 1] + D[i][j];
                columnIndexOfPreNode[i][j] = j - 1;
            }
            else
            {
                minSum[i][j] = minSum[i - 1][j] + D[i][j];
                columnIndexOfPreNode[i][j] = j;
            }
        }
    }

    int sum = minSum[N][1];      // sum为从顶部到底部的最小和
    int columnIndex = 1;         // 终点结点的列下标
    for (int j = 2; j <= N; j++) // 求出从顶部到底部的最小和、终点结点的列下标
    {
        if (minSum[N][j] < sum)
        {
            sum = minSum[N][j];
            columnIndex = j;
        }
    }
    *k = columnIndex;

    return sum;
}

void getNumsOnPath(int N, int D[][MAX_N + 1], int columnIndexOfPreNode[][MAX_N + 1], int k, int numsOnPath[MAX_N + 1])
{
    // 在求出从顶部到底部的最大/小和sum之后，通过columnIndexOfPreNode[N][k]可求出求得反向路径上的数字序列（即从叶结点D[N][k]到根结点D[1][1]的最大/小和路径上的数字序列），将该数字序列反转存入numsOnPath数组，即可得到从顶部到底部的最大/小和路径上的数字序列
    numsOnPath[N] = D[N][k];
    int j = columnIndexOfPreNode[N][k];
    for (int i = N - 1; i >= 2; i--)
    {
        numsOnPath[i] = D[i][j];
        j = columnIndexOfPreNode[i][j];
    }
    numsOnPath[1] = D[1][1];
}

int main()
{
    int D[MAX_N + 1][MAX_N + 1] = {0};      // 用二维数组D存放数字三角形。称每个数组元素为结点，称D[1][1]为根节点
    int maxSum[MAX_N + 1][MAX_N + 1] = {0}; // maxSum[i][j]表示从根结点D[1][1]到结点D[i][j]的最大和
    int minSum[MAX_N + 1][MAX_N + 1] = {0}; // minSum[i][j]表示从根结点D[1][1]到结点D[i][j]的最小和
    int columnIndexOfPreNode1[MAX_N + 1][MAX_N + 1] = {0};
    int columnIndexOfPreNode2[MAX_N + 1][MAX_N + 1] = {0};
    // columnIndexOfPreNode2[i][j]里保存的是什么？从根结点D[1][1]到结点D[i][j]的最小和路径上，结点D[i][j]的前驱结点的列下标
    // 由于结点D[i][j]的前驱结点只有两个，即结点D[i-1][j-1]和结点D[i-1][j]，这两个结点的行下标都是i-1，因此记录其前驱结点的列下标即可唯一确定其前驱结点
    // 在求出从顶部到底部的最小和sum2之后，通过columnIndexOfPreNode2[N][k]可求出求出反向路径（即从叶结点D[N][k]到根结点D[1][1]的一条路径），最后正向输出该路径即可得到从顶部到底部的最小和路径
    int numsOnPath1[MAX_N + 1] = {0};
    int numsOnPath2[MAX_N + 1] = {0};

    int N;
    scanf("%d", &N); // 数字三角形的行数
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%d", &D[i][j]);
        }
    }

    // printf("---------------------\n");
    int k1 = -1;
    int sum1 = getMaxSum(N, D, maxSum, columnIndexOfPreNode1, &k1); // sum1为从顶部到底部的最大和
    // getNumsOnPath(N, D, columnIndexOfPreNode1, k1, numsOnPath1);
    // for (int i = 1; i <= N; i++) // 输出从顶部到底部的最大和路径上的数字
    // {
    //     printf("%d ", numsOnPath1[i]);
    // }
    // printf("\n");
    printf("%d\n", sum1); // 输出从顶部到底部的最大和

    // printf("---------------------\n");
    // int k2 = -1;
    // int sum2 = getMinSum(N, D, minSum, columnIndexOfPreNode2, &k2); // sum2为从顶部到底部的最小和
    // getNumsOnPath(N, D, columnIndexOfPreNode2, k2, numsOnPath2);
    // for (int i = 1; i <= N; i++) // 输出从顶部到底部的最小和路径上的数字
    // {
    //     printf("%d ", numsOnPath2[i]);
    // }
    // printf("\n");
    // printf("%d\n", sum2); // 输出从顶部到底部的最小和

    return 0;
}