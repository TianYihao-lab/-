#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void test01();
void test02();

int main(){
    //test01();
    test02();
    return 0;
}

void test01(){
    string str;
    cin>>str;
    cout << str << endl;
}

void test02(){
    string str;
    getline(cin,str);
    cout << str;
}