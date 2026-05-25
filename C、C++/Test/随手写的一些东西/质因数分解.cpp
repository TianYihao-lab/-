#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
#define N 1e5+10
#define PI 3.14

long long int n;

bool is_Prime(int n){
	if(n%2==0)return false;
	for(int i=3;i<=sqrt(n);i+=2){
		if(n%i==0)return false;
	}
	return true;
}
void test01(){
	cin>>n;
	for(int i=3;i<=sqrt(n);i+=2){
		if(is_Prime(i)&&n%i==0){
			//cout<<i<<endl;
			cout<<n/i<<endl;
			break;
		}
	}
}
int main(){
	test01();
	return 0;
}
