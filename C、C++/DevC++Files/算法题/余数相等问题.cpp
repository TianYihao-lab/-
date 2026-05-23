#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
#define PI 3.14
const int N=1e5+10;

int a,b,c;

void test01(){
	cin>>a>>b>>c;
	for(int i=2;i<=min(a,max(b,c));i++){
		if(a%i==b%i&&a%i==c%i&&b%i==c%i){
			cout<<i<<endl;
			break;
		}
	}
}
int main(){
	test01();
	return 0;
}
