#include<iostream>   // C++语言的标准库
#include<cstdio>     // C语言的标准库
#include<cmath>      // 数学函数库
#include<algorithm>  // 算法函数库
#include<string>     // C++字符串函数库   -- STL库
#include<cstring>    // C风格字符串函数库
using namespace std;  // 命名空间申明
#define PI 3.14
const int N=1e5+10;

int n;
string s1,s2;
int judje(string s1,string s2){
    if(s1=="Rock"&&s2=="Scissors")return 1;
    if(s1=="Rock"&&s2=="Rock")return 0;
    if(s1=="Rock"&&s2=="Paper")return 2;

    if(s1=="Scissors"&&s2=="Rock")return 2;
    if(s1=="Scissors"&&s2=="Scissors")return 0;
    if(s1=="Scissors"&&s2=="Paper")return 1;

    if(s1=="Paper"&&s2=="Rock")return 1;
    if(s1=="Paper"&&s2=="Scissors")return 2;
    if(s1=="Paper"&&s2=="Paper")return 0;

    return 0;
}
void test01(){
	cin>>n;
    while(n--){
        cin>>s1>>s2;
        if(judje(s1,s2)==0)cout<<"Tie"<<endl;
        else cout<<"Player"<<judje(s1,s2)<<endl;
    }
}
int main(){
	test01();
	return 0;
}