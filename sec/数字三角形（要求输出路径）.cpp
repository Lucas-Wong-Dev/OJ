// 数字三角形（要求输出路径）
/*
给定高度为n的一个整数三角形
请编一个程序计算从顶至底的某处的一条路径，使该路径所经过的数字的总和最大。

首先输入n，
接下来的1～n行，第i行输入i个整数，

输出分为2行，
第一行为“最大和路径上的数字”，第2行为“从顶部到底部的最大和”
*/
/* 
状态转移方程
这里有两个边界，即第1列和对角线，达到它们中结点的路径只有一条而不是常规的两条
所以状态转移方程如下：
dp[1][1]=a[1][1] 顶部边界
dp[i][1]=dp[i-1][1]+a[i][1] 第1列的边界
dp[i][i]=dp[i-1][i-1]+a[i][i] 对角线的边界
dp[i][j]=min(dp[i-1][j-1], dp[i-1][j])+a[i][j]  其他有两条达到路径的结点
*/
#include <stdio.h>
#include <string.h>

const int MAX_n = 100; // 数字三角形的最大行数

int searchMinimalSum(int n, int a[][MAX_n + 1], int minimalSum[][MAX_n + 1], int columnIndexOfPreNode[][MAX_n + 1], int *k)
{
    minimalSum[1][1] = a[1][1]; // 根结点

    for (int i = 2; i <= n; i++) // 第1列上的结点
    {
        minimalSum[i][1] = minimalSum[i - 1][1] + a[i][1];
        columnIndexOfPreNode[i][1] = 1; // 结点a[i][1]的前驱结点只有结点a[i-1][1]
    }

    for (int i = 2; i <= n; i++) // 对角线上的结点
    {
        minimalSum[i][i] = minimalSum[i - 1][i - 1] + a[i][i];
        columnIndexOfPreNode[i][i] = i - 1; // 结点a[i][1]的前驱结点只有结点a[i-1][i-1]
    }

    for (int i = 3; i <= n; i++) // 其他有两个前驱结点的结点
    {
        for (int j = 2; j <= i - 1; j++)
        {
            if (minimalSum[i - 1][j - 1] < minimalSum[i - 1][j])
            {
                minimalSum[i][j] = minimalSum[i - 1][j - 1] + a[i][j];
                columnIndexOfPreNode[i][j] = j - 1;
            }
            else
            {
                minimalSum[i][j] = minimalSum[i - 1][j] + a[i][j];
                columnIndexOfPreNode[i][j] = j;
            }
        }
    }

    int sum = minimalSum[n][1];  // 最小和
    int column = 1;              // 终点结点的列下标
    for (int j = 2; j <= n; j++) // 求出最小和、终点结点的列下标
    {
        if (minimalSum[n][j] < sum)
        {
            sum = minimalSum[n][j];
            column = j;
        }
    }
    *k = column;

    return sum;
}

int searchMaximalSum(int n, int a[][MAX_n + 1], int maximalSum[][MAX_n + 1], int columnIndexOfPreNode[][MAX_n + 1], int *k) // AC 用这个函数测试了下数字三角形那题，成功AC了
{
    maximalSum[1][1] = a[1][1]; // 根结点

    for (int i = 2; i <= n; i++) // 第1列上的结点
    {
        maximalSum[i][1] = maximalSum[i - 1][1] + a[i][1];
        columnIndexOfPreNode[i][1] = 1; // 结点a[i][1]的前驱结点只有结点a[i-1][1]
    }

    for (int i = 2; i <= n; i++) // 对角线上的结点
    {
        maximalSum[i][i] = maximalSum[i - 1][i - 1] + a[i][i];
        columnIndexOfPreNode[i][i] = i - 1; // 结点a[i][1]的前驱结点只有结点a[i-1][i-1]
    }

    for (int i = 3; i <= n; i++) // 其他有两个前驱结点的结点
    {
        for (int j = 2; j <= i - 1; j++)
        {
            if (maximalSum[i - 1][j - 1] > maximalSum[i - 1][j])
            {
                maximalSum[i][j] = maximalSum[i - 1][j - 1] + a[i][j];
                columnIndexOfPreNode[i][j] = j - 1;
            }
            else
            {
                maximalSum[i][j] = maximalSum[i - 1][j] + a[i][j];
                columnIndexOfPreNode[i][j] = j;
            }
        }
    }

    int sum = maximalSum[n][1];  // 最大和
    int column = 1;              // 终点结点的列下标
    for (int j = 2; j <= n; j++) // 求出最大和、终点结点的列下标
    {
        if (maximalSum[n][j] > sum)
        {
            sum = maximalSum[n][j];
            column = j;
        }
    }
    *k = column;

    return sum;
}

void getNumsOnPath(int n, int a[][MAX_n + 1], int columnIndexOfPreNode[][MAX_n + 1], int k, int numsOnPath[MAX_n + 1])
{
    // 在求出从顶部到底部的最大/小和sum之后，通过columnIndexOfPreNode[n][k]可求出求得反向路径上的数字序列（即从叶结点a[n][k]到根结点a[1][1]的一条路径上的数字序列），将该数字序列反转存入numsOnPath数组，即可得到从顶部到底部的最大/小和路径
    numsOnPath[n] = a[n][k];
    int j = columnIndexOfPreNode[n][k];
    for (int i = n - 1; i >= 2; i--)
    {
        numsOnPath[i] = a[i][j];
        j = columnIndexOfPreNode[i][j];
    }
    numsOnPath[1] = a[1][1];
}

int main()
{
    int a[MAX_n + 1][MAX_n + 1] = {0};          // 用二维数组a存放数字三角形。称每个数组元素为结点，称a[1][1]为根节点
    int minimalSum[MAX_n + 1][MAX_n + 1] = {0}; // minimalSum[i][j]表示从根结点a[1][1]到结点a[i][j]的最小和
    int maximalSum[MAX_n + 1][MAX_n + 1] = {0}; // maximalSum[i][j]表示从根结点a[1][1]到结点a[i][j]的最大和
    int columnIndexOfPreNode1[MAX_n + 1][MAX_n + 1] = {0};
    // columnIndexOfPreNode[i][j]里保存的是什么？从根结点a[1][1]到结点a[i][j]的最小和路径上，结点a[i][j]的前驱结点的列下标
    // 由于结点a[i][j]的前驱结点只有两个，即结点a[i-1][j-1]和结点a[i-1][j]，这两个结点的行下标都是i-1，因此记录其前驱结点的列下标即可唯一确定其前驱结点
    // 在求出从顶部到底部的最小和sum1之后，通过columnIndexOfPreNode[n][k]可求出求出反向路径（即从叶结点a[n][k]到根结点a[1][1]的一条路径），最后正向输出该路径即可得到从顶部到底部的最小和路径
    int columnIndexOfPreNode2[MAX_n + 1][MAX_n + 1] = {0};
    int numsOnPath1[MAX_n + 1] = {0};
    int numsOnPath2[MAX_n + 1] = {0};

    int n;
    scanf("%d", &n); // 数字三角形的行数
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("---------------------\n");
    int k1 = -1;
    int sum1 = searchMinimalSum(n, a, minimalSum, columnIndexOfPreNode1, &k1); // sum1为从顶部到底部的最小和
    getNumsOnPath(n, a, columnIndexOfPreNode1, k1, numsOnPath1);
    for (int i = 1; i <= n; i++) // 输出从顶部到底部的最小和路径上的数字
    {
        printf("%d ", numsOnPath1[i]);
    }
    printf("\n");
    printf("%d\n", sum1); // 输出从顶部到底部的最小和

    printf("---------------------\n");
    int k2 = -1;
    int sum2 = searchMaximalSum(n, a, minimalSum, columnIndexOfPreNode2, &k2); // sum2为从顶部到底部的最大和
    getNumsOnPath(n, a, columnIndexOfPreNode2, k2, numsOnPath2);
    for (int i = 1; i <= n; i++) // 输出从顶部到底部的最小和路径上的数字
    {
        printf("%d ", numsOnPath2[i]);
    }
    printf("\n");
    printf("%d\n", sum2); // 输出从顶部到底部的最大和

    return 0;
}
