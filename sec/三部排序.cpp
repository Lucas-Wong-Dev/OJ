// 三部排序 - 填空题
/*
三部排序
一般的排序有许多经典算法，如快速排序、希尔排序等。但实际应用时，经常会或多或少有一些特殊的要求。我们没必要套用那些经典算法，可以根据实际情况建立更好的解法。
比如，对一个整型数组中的数字进行分类排序：使得负数都靠左端，正数都靠右端，0 在中部。
注意问题的特点是：负数区域和正数区域内并不要求有序。可以利用这个特点通过1次线性扫描就结束战斗!

以下的程序实现了该目标。
其中x指向待排序的整型数组，len是数组的长度。

输 入 ： 1 0 1 0 -2 -8 3 0 5 -10
输 出 ： -10 -2 -8 0 0 0 3 5 1 1
*/
#include <iostream>
using namespace std;

void print(int *x, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", x[i]);
    }
    cout << endl;
}

void Sort3p(int *x, int len)
{
    int p = 0;
    int left = 0;
    int right = len - 1;

    while (p <= right)
    {
        if (x[p] < 0)
        {
            // cout << x[p] << "<0 " << endl;
            // print(x, 10);
            // cout << "p==" << p << " left==" << left << " right==" << right << endl;

            int temp = x[left];
            x[left] = x[p];
            x[p] = temp;

            p++;
            left++;

            // cout << "p==" << p << " left==" << left << " right==" << right << endl;
            // print(x, 10);
            // cout << "----------" << endl;
        }
        else if (x[p] > 0)
        {
            // cout << x[p] << ">0 " << endl;
            // print(x, 10);
            // cout << "p==" << p << " left==" << left << " right==" << right << endl;

            int temp = x[right];
            x[right] = x[p];
            x[p] = temp;

            right--;

            // cout << "p==" << p << " left==" << left << " right==" << right << endl;
            // print(x, 10);
            // cout << "----------" << endl;
        }
        else
        {
            // cout << x[p] << "==0 " << endl;
            // print(x, 10);
            // cout << "p==" << p << " left==" << left << " right==" << right << endl;
            p++; // 填空位置
            // cout << "p==" << p << " left==" << left << " right==" << right << endl;
            // print(x, 10);
            // cout << "----------" << endl;
        }
    }
}
int main()
{
    const int len = 10;
    int x[len];
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &x[i]);
    }
    Sort3p(x, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", x[i]);
    }
    return 0;
}