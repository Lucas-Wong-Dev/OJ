// #include <stdio.h>
// int main()
// {

//     char *p1 = 0;
//     int *p2 = 0;
//     float *p3 = 0;
//     // printf("%d %d %d", sizeof(p1), sizeof(p2), sizeof(p3));
//     p1 = (char *)p2;
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     enum weekday
//     {
//         sun = 1,
//         mon = 0,
//         tue,
//         wed,
//         thu,
//         fri,
//         sat
//     } x;
//     x = tue;
//     printf("%d\n", x);
//     x = sun;
//     printf("%d\n", x);
//     printf("%d\n", sun);
//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//     auto ans1 = 5 % 2;
//     // auto ans2 = 5.0 % 2;   // expression must have integral or unscoped enum type
//     // auto ans3 = 5 % 2.0;   // expression must have integral or unscoped enum type
//     // auto ans4 = 5.0 % 2.0; // expression must have integral or unscoped enum type
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     // int m[] = {5, 4, 3, 2, 1}, i = 0;
//     // printf("%d\n", m[m[4]]);
//     int a = 0, b = 1;
//     printf("%d %d", a);
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     int b1, b2, b3;
//     for (int a = 0; a <= 1000; a++)
//     {
//         b1 = a >> 3 % 4; //
//         printf("%d,%d ", a, b1);
//         b2 = (a >> 3) % 4;
//         printf("%d,%d ", a, b2);
//         b3 = a >> (3 % 4); //
//         printf("%d,%d\n", a, b3);
//         if (b1 != b2 || b1 != b3 || b2 != b3)
//         {
//             printf("#found\ta==%d", a);
//             break;
//         }
//     }

//     return 0;
// }

// // #include <stdio.h>
// // int main()
// // {
// //     int n, m;
// //     scanf("%d%d", &n, &m);
// //     long sum = 0;
// //     for (int i = m; i >= 1; i--)
// //     {
// //         int temp = 1;
// //         for (int j = 1; j <= n; j++)
// //         {
// //             temp++;
// //         }
// //     }

// //     printf("%ld\n", sum);

// //     return 0;
// // }
