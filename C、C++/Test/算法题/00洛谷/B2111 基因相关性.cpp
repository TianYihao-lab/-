#include<iostream>   // C++语言的标准库
#include<cstdio>     // C语言的标准库
#include<cmath>      // 数学函数库
#include<algorithm>  // 算法函数库
#include<string>     // C++字符串函数库   -- STL库
#include<cstring>    // C风格字符串函数库
using namespace std;  // 命名空间申明
#define PI 3.14
const int N=1e5+10;

double n;
string s1,s2;

void test01(){
    cin>>n;
    cin>>s1>>s2;
    int cnt=0,len=s1.length();
    for(int i=0;i<len;i++){
        if(s1[i]==s2[i])cnt++;
    }
    (1.0*cnt/len>=n)? cout<<"yes"<<endl:cout<<"no"<<endl;
    //(1.0 * cnt >= n) ? cout << "yes" << endl : cout << "no" << endl;
}
int main(){
	test01();
	return 0;
}