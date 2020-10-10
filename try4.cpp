#include <stdio.h>
int main()
{
    freopen("test.txt", "w", stdout);
    for (int i = 1; i <= 100; i++)
    {
        printf("%d ", i);
    }
    return 0;
}