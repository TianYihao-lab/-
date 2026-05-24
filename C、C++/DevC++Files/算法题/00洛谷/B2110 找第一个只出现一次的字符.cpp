#include<iostream>   // C++语言的标准库
#include<cstdio>     // C语言的标准库
#include<cmath>      // 数学函数库
#include<algorithm>  // 算法函数库
#include<string>     // C++字符串函数库   -- STL库
#include<cstring>    // C风格字符串函数库
using namespace std;  // 命名空间申明
#define PI 3.14
const int N=1e5+10;

int arr[26];
string s;

void test01(){
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        arr[s[i]-'a']++;
    }
    for(int i=0;i<len;i++)
        if(arr[i]==1){
            cout<<(char)('a'+i)<<endl;
            return;
        }
    cout<<"no"<<endl;
}
int main(){
	test01();
	return 0;
}