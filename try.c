#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, index = 0; // index是数组ans的下标
    int ans[100];

    scanf("%d", &n);

    if (n == 0)
        printf("%d", n);
    while (n != 0)
    {
        ans[index] = n % 16;
        n = n / 16;
        index++;
    }
    for (int i = index - 1; i >= 0; i--)
    {
        if (ans[i] >= 10)
            printf("%c", (ans[i] - 10 + 'A'));
        else
            printf("%c", (ans[i] + '0')); // AC
            // printf("%d", ans[i]); // AC
    }
    return 0;
}
