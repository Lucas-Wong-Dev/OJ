// 出现次数最多的整数
/*
问题描述
编写一个程序，读入一组整数，这组整数是按照从小到大的顺序排列的，

它们的个数N也是由用户输入的，最多不会超过20。然后程序将对这个数组进行统计，把出现次数最多的那个数组元素值打印出来。
如果有两个元素值出现的次数相同，即并列第一，那么只打印比较小的那个值。

输入格式：
第一行是一个整数N，N小于20；
接下来有N行，每一行表示一个整数，并且按照从小到大的顺序排列。

输出格式：
输出只有一行，即出现次数最多的那个元素值。

样例输入
5
100
150
150
200
250
样例输出
150
*/
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int *a = new int[N];
    int elementWithMaxOccurrence, maxOccurrence = 1, currentElementOccurrence = 1;

    cin >> a[0];
    elementWithMaxOccurrence = a[0];

    for (int i = 1; i < N; i++)
    {
        cin >> a[i];
        if (a[i] == a[i - 1])
        {
            currentElementOccurrence++;
            if (currentElementOccurrence > maxOccurrence)
            {
                maxOccurrence = currentElementOccurrence;
                elementWithMaxOccurrence = a[i];
            }
        }
        else
        {
            currentElementOccurrence = 1;
        }
    }

    cout << elementWithMaxOccurrence;

    delete[] a;

    return 0;
}


/*
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int arr[N];

    int curElemOccur = 1;
    int maxOccur = 1;

    cin >> arr[0];
    int elemWithMaxOccur = arr[0];

    for (int i = 1; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] == arr[i - 1])
        {
            curElemOccur++;
            if (curElemOccur > maxOccur)
            {
                elemWithMaxOccur = arr[i];
            }
        }
        else
        {
            curElemOccur = 1;
        }
    }

    cout << elemWithMaxOccur << endl;
    
    return 0;
}
*/