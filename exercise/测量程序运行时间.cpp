// #include <stdio.h>
// #include <time.h> // ★

// int main()
// {
//     clock_t start_time, end_time;
//     double duration_time;
//     start_time = clock();

//     long i = 1000000000L;
//     while (i--)
//         ;

//     end_time = clock();
//     duration_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     printf("duration: %lf seconds\n", duration_time);
// }

#include <stdio.h>
#include <time.h>   // ★
#include <limits.h> // ★
int main()
{
    time_t start_time = time(NULL);

    // int i = INT_MAX;
    int i = 500;
    while (i--)
        ;

    // printf("%d %lld\n", INT_MAX, time(NULL) - start_time);
    printf("%lld\n", time(NULL) - start_time);

    return 0;
}
