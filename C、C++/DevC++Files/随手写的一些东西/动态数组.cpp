#include<iostream>
#include<vector>
using namespace std;

void test02()
{
    vector<vector<int>> v;

    vector<int> v1, v2, v3;

    // 对小数组赋值
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);

    // 对大数组赋值
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator its = (*it).begin(); its != (*it).end(); its++)
        {
            cout << *its;
        }
        puts("");
    }
}

void test03(){
    string str3; 
    str3.assign("hello");
    cout << "str3=" << str3 << endl;

    string str2 = "hello";
    str2.append(" C++");
    str2.append(" STLXXXXXXX", 4);
    cout << str2 << endl;
}

int main(){
    //test02();
    test03();
    return 0;
}