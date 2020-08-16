// 三部排序
/*
三部排序
一般的排序有许多经典算法，如快速排序、希尔排序等。但实际应用时，经常会或多或少有一些特殊的要求。我们没必要套用那些经典算法， 可以根据实际情况建立更好的解法。
比如，对一个整型数组中的数字进行分类排序：使得负数都靠左端，正数都靠右端，0 在中部。
注意问题的特点是：负数区域和正数区域内并不要求有序。可以利用这个特点通过 1 次线性扫描就结束战斗!!

以下的程序实现了该目标。
其中x 指向待排序的整型数组，len是数组的长度。

输 入 ： 1 0 1 0 -2 -8 3 0 5 -10
输 出 ： -10 -2 -8 0 0 0 3 5 1 1
*/
#include <iostream>
using namespace std;
void print(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    cout << endl;
}
void Sort3p(int *arr, int len)
{
    int p = 0, temp; 
    int left = 0;
    int right = len - 1;
    while (p <= right)
    {
        if (arr[p] < 0)
        {
            cout << arr[p] << "<0 " << endl;
            print(arr, 10);
            cout << "p==" << p << " left==" << left << " right==" << right << endl;
            temp = arr[left];
            arr[left] = arr[p];
            arr[p] = temp;
            p++;
            left++;
            cout << "p==" << p << " left==" << left << " right==" << right << endl;
            print(arr, 10);
            cout << "----------" << endl;
        }
        else if (arr[p] > 0)
        {
            cout << arr[p] << ">0 " << endl;
            print(arr, 10);
            cout << "p==" << p << " left==" << left << " right==" << right << endl;
            temp = arr[right];
            arr[right] = arr[p];
            arr[p] = temp;
            right--;
            cout << "p==" << p << " left==" << left << " right==" << right << endl;
            print(arr, 10);
            cout << "----------" << endl;
        }
        else
        {
            cout << arr[p] << "==0 " << endl;
            print(arr, 10);
            cout << "p==" << p << " left==" << left << " right==" << right << endl;
            p++;
            cout << "p==" << p << " left==" << left << " right==" << right << endl;
            print(arr, 10);
            cout << "----------" << endl;
        }
    }
}
int main()
{
    const int LenOfArr = 10;
    int arr[LenOfArr];
    for (int i = 0; i < LenOfArr; i++)
    {
        scanf("%d", &arr[i]);
    }
    Sort3p(arr, LenOfArr);
    for (int i = 0; i < LenOfArr; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}