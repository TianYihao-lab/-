#include <iostream>  // C++语言的标准库
#include <cstdio>    // C语言的标准库
#include <cmath>     // 数学函数库
#include <algorithm> // 算法函数库
#include <string>    // C++字符串函数库   -- STL库
#include <cstring>   // C风格字符串函数库
using namespace std; // 命名空间申明
#define PI 3.14
const int N = 1e5 + 10;

string s;

void test01()
{
    cin >> s;
    if (s[0] >= '0' && s[0] <= '9')
    {
        cout << "no" << endl;
        return;
    }

    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (!(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] == '_'))
        {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}
int main()
{
    test01();
    return 0;
}