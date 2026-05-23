#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
#define N 1e5+10
#define PI 3.14

void test01(){
	int x,y;
    char c;
    cin>>x>>y>>c;
    if(c=='+'){
        cout<<x+y<<endl;
    }else if(c=='-'){
        cout<<x-y<<endl;
    }else if(c=='*'){
        cout<<x*y<<endl;
    }else if(c=='/'){
        if(y==0){
            cout<<"Divided by zero!";
        }
        cout<<(int)(x/y)<<endl;
    }
    else cout<<"Invalid operator!";
}
int main(){
	test01();
	return 0;
}
