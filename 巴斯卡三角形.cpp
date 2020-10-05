// 巴斯卡三角形
/*
1
1	1
1	2	1
1	3	3	1
1	4	6	4	1
1	5	10	10	5	1
1	6	15	20	15	6	1
1	7	21	35	35	21	7	1
1	8	28	56	70	56	28	8	1
1	9	36	84	126	126	84	36	9	1
*/
#include <stdio.h>
const int N = 12; // 输出12行
long combi(int n, int m)
{
    long ans = 1;
    for (int i = 1; i <= m; i++){
        // printf("%d*(%d-%d+1)/%d=", ans, n, i, i);
        ans = ans * (n - i + 1) / i;
        // printf("%d\n", ans);
    }
    // printf("--->%d", ans);
    return ans;
}
void paint()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                for (int k = 0; k <= (N - i); k++)
                    printf("   ");
            }
            else
            {
                printf("   ");
            }
            printf("%3d", combi(i, j));
        }
        printf("\n");
    }
}
int main()
{
    paint();
    // combi(3, 2);
    return 0;
}