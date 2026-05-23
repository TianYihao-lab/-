#include<bits/stdc++.h>
using namespace std;  // ÃüÃû¿Õ¼äÉêÃ÷
#define PI 3.14
const int N=1e5+10;

char c[N];
int n,cnt;

void test01(){
	gets(c);
    // int len=strlen(c);
    while(c[n++]!='\0')
        if(isdigit(c[n]))
            cnt++;
    cout<<cnt<<endl;
}
// string s;
// int cnt;

// void test02(){
//     cin>>s;
//     cout<<s<<endl;
// }
int main(){
	test01();
	return 0;
}