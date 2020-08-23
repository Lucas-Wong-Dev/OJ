// 数的读法
/*
问题描述
Tom 教授正在给研究生讲授一门关于基因的课程，有一件事情让他颇为头疼：一条染色体上有成千上万个碱基对，它们从0开始编号，到几百万，几千万，甚至上亿。
比如说，在对学生讲解第1234567009号位置上的碱基时，光看着数字是很难准确的念出来的。
所以，他迫切地需要一个系统，然后当他输入1234567009时，会给出相应的念法： 十二亿三千四百五十六万七千零九
用汉语拼音表示为
shi er yi san qian si bai wu shi liu wan qi qian ling jiu
这样他只需要照着念就可以了。

你的任务是帮他设计这样一个系统：给定一个阿拉伯数字串，你帮他按照中文读写的规范转为汉语拼音字串，相邻的两个音节用一个空格符格开。
注意必须严格按照规范，

比如说“10010”读作“yi wan ling yi shi”而不是“yi wan ling shi”
“100000”读作“shi wan”而不是“yi shi wan”
“2000”读作“er qian”而不是“liang qian”

输入格式
有一个数字串，数值大小不超过 2,000,000,000。
输出格式
是一个由小写英文字母，逗号和空格组成的字符串，表示该数的英文读法。

样例输入
1234567009
样例输出
shi er yi san qian si bai wu shi liu wan qi qian ling jiu
*/

#include <iostream>
using namespace std;
string b[10] = {"ling ", "yi ", "er ", "san ", "si ", "wu ", "liu ", "qi ", "ba ", "jiu "};
string func(string t)
{
    string ans;
    int lenOft = t.length();
    if (lenOft >= 4) // lenOft >= 4
    {
        ans += b[t[0] - '0'];
        ans += "qian ";
    }
    if (lenOft >= 3) // lenOft == 3
    {
        if (t[lenOft - 3] != '0')
        {
            ans += b[t[lenOft - 3] - '0'];
            ans += "bai ";
        }
    }
    if (lenOft >= 2) // lenOft == 2
    {
        if (t[lenOft - 2] == '1')
        {
            if (lenOft != 2)
            {
                ans += "yi shi ";
            }
            else
            {
                ans += "shi ";
            }
        }
        if (t[lenOft - 2] != '0' && t[lenOft - 2] != '1')
        {
            ans += b[t[lenOft - 2] - '0'];
            ans += "shi ";
        }
    }
    if (lenOft >= 1) // lenOft == 1
    {
        if (t[lenOft - 1] != '0')
        {
            ans += b[t[lenOft - 1] - '0'];
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int lenOfs = s.length();
    string sub;
    if (lenOfs == 10)
    {
        sub = s.substr(0, 2);
        cout << func(sub) << "yi ";
    }
    if (lenOfs == 9)
    {
        sub = s.substr(0, 1);
        cout << func(sub) << "yi ";
    }
    sub = "";
    bool flag = false;
    if (lenOfs >= 5)
    {
        for (int i = lenOfs - 8; i < lenOfs - 4; i++)
        {
            if (i < 0)
                continue;
            if (flag == false && s[i] == '0')
            {
                continue;
            }
            sub += s[i];
            flag = true;
        }
        if (flag == true)
        {
            cout << func(sub) << "wan ";
        }
        sub = "";
        flag = false;
        for (int i = lenOfs - 4; i < lenOfs; i++)
        {
            // if (i < 0)
            //     continue; // 这两行代码实际上没必要加上，因为只要程序进入了这个for循环，lenOfs就必然大于等于5，i=lenOfs-4就必然大于等于1
            if (flag == false && s[i] == '0')
            {
                continue;
            }
            if (
                (i == lenOfs - 1 && s[i - 1] == '0') || 
                (i == lenOfs - 2 && s[i - 1] == '0') || 
                (i == lenOfs - 3 && s[i - 1] == '0')
            )
                cout << "ling ";
            sub += s[i];
            flag = true;
        }
    }
    if (lenOfs <= 4)
    {
        sub = s;
        flag = true;
    }
    if (flag == true)
    {
        cout << func(sub);
    }
    return 0;
}
