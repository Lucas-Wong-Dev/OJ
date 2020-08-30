// 第39台阶
/*
如果我每一步迈上1个或2个台阶，先迈左脚，然后左右交换，最后一步迈右脚， 也就是一共要走偶数步，
那么，上完 39 级台阶，有多少种不同的算法
*/
/*
思路：
不管走的是左脚还是右脚，只要走的步数是偶数即可
递归
39,0
38,1	37,1
37,2	36,2	36,2	35,2
...	...	...	...	...	...	...	...
输出：Total=51167078
*/

//方法1：从顶部算（better）
#include <iostream>
using namespace std;
long long cnt = 0;
void count(int step, int num)
{
    // 在进行函数体内的操作前
    // 1、已走了step步
    // 2、还剩num个台阶没走
    if (num < 0)
    {
        return;
    }
    if (num == 0 && step % 2 == 0)
    {
        cnt++;
        return;
    }
    count(step + 1, num - 1);
    count(step + 1, num - 2);
}
int main()
{
    int num;
    cin >> num;
    count(0, num);
    cout << cnt << endl;
    return 0;
}

// // 方法2：从底部算
// #include <iostream>
// using namespace std;
// long long cnt = 0;
// void count(int step, int num)
// {
//     // 在进行函数体内的操作前
//     // 1、已走了step步
//     // 2、已走了num个台阶
//     if (num > 39)
//     {
//         return;
//     }
//     if (num == 39 && step % 2 == 0)
//     {
//         cnt++;
//         return;
//     }
//     count(step + 1, num + 1);
//     count(step + 1, num + 2);
// }
// int main()
// {
//     count(0, 0);
//     cout << cnt << endl;
//     return 0;
// }