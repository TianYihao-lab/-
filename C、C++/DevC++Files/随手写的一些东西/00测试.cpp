#include <iostream>
using namespace std;
void test01()
{
    int n;
    cout << "输入：";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    puts("");
}
void test02()
{
    for (int i = 0; i < 5; i++)
    {
        cout << i << " ";
    }
    puts("");
}
int main()
{
    cout<<"你好"<<endl;
    //test01();
    return 0;
}