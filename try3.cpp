// #include <iostream>
// #include <cmath>
// using namespace std;
// void fun(int x)
// {
//     int index = (int)(log(x) / log(2));
//     int remainingPart = x - pow(2, index);
//     if (index == 0)
//     {
//         cout << "2(0)";
//         return;
//     }
//     else if (index == 1)
//     {
//         cout << "2";
//         return;
//     }
//     else
//     {
//         cout << "2(";
//         fun(index);
//         cout << ")";
//     }
//     if (remainingPart)
//     {
//         cout << "+";
//         fun(remainingPart);
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     fun(n);
//     return 0;
// }
// 73
// 2(2(2)+2)+2(2)+2(0)
// 2(2(2)+2)+2(2+2(0))+2(0)

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout << log(3)/log(2) << endl;
    return 0;
}