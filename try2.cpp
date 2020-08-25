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

    ans.push_front(arr.back());
    arr.pop_back();
    bool odd = true;

    while(!arr.empty()){
        if(odd){
            ans.push_front(arr.back());
            arr.pop_back();
            odd=false;
        }
        else{
            ans.push_front(ans.back());
            ans.pop_back();
            odd=true;
        }
    }

    ans.push_front(ans.back());
    ans.pop_back();

    return 0;
}