/*
小明刚上小学，学会了第一个扑克牌“魔术”，到处给人表演。魔术的内容是这样的：

他手里握着一叠扑克牌：A，2，....J，Q，K 一共13张。他先自己精心设计它们的顺序，然后正面朝下拿着，开始表演。

只见他先从最下面拿一张放到最上面，再从最下面拿一张翻开放桌子上，是A；然后再从最下面拿一张放到最上面，再从最下面拿一张翻开放桌子上，是2；......如此循环直到手中只有一张牌，翻开放桌子上，刚好是K。

这时，桌上牌的顺序是：A,2,3,4,5,6,7,8,9,10,J,Q,K

请你计算一下，小明最开始的时候手里牌的顺序是怎样的。

把结果写出来，逗号分割，小明“魔术”开始时，最下面的那张牌输出为第一个数据。

考场不提供扑克牌，你只能用计算机模拟了，撕碎草稿纸模拟扑克属于作弊行为！另外，你有没有把录像倒着放过？很有趣的！回去试试！
*/

/*
7,A,Q,2,8,3,J,4,9,5,K,6,10
满分 6 分
*/
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<char> arr;
    deque<char> ans;

    arr.push_back('A');
    arr.push_back('2');
    arr.push_back('3');
    arr.push_back('4');
    arr.push_back('5');
    arr.push_back('6');
    arr.push_back('7');
    arr.push_back('8');
    arr.push_back('9');
    arr.push_back('T'); // T代表10
    arr.push_back('J');
    arr.push_back('Q');
    arr.push_back('K');

    bool odd = true;

    ans.push_front(arr.back());
    arr.pop_back();

    while (!arr.empty())
    {
        if (odd)
        {
            ans.push_front(arr.back());
            arr.pop_back();
            odd = false;
        }
        else
        {
            ans.push_front(ans.back());
            ans.pop_back();
            odd = true;
        }
    }
    ans.push_front(ans.back());
    ans.pop_back();

    cout << ans.at(0);
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans.at(i) == 'T')
        {
            cout << ","
                 << "10";
        }
        else
        {
            cout << "," << ans.at(i);
        }
    }

    return 0;
}
