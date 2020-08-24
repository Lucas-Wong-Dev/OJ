// 【结果填空题】 有趣的平方数
/*
625 这个数字很特别，625 的平方等于 390625，刚好其末 3 位是 625 本身。除了 625，
还有其它的 3 位数有这个特征吗？还有一个！该数是： 	
【参考答案】
376
*/
#include <iostream>
using namespace std;
int main()
{
    for (int i = 100; i <= 999; i++)
    {
        int i2 = i * i;
        int a = i2 % 10; 
        int b = i2 / 10 % 10;
        int c = i2 / 100 % 10;
        if (c * 100 + b * 10 + a == i)
        {
            cout << i << endl;
        }
    }
    return 0;
}