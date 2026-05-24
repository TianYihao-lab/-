#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
const int N=1e5+10;
#define PI 3.14

int n;
int nums[N];

int Que(int n){
	if(n==1)return 1;
	if(n==2)return 2;
	if(nums[n]!=0)return nums[n];
	nums[n]=Que(n-1)+Que(n-2);
	return nums[n];
}

void test01(){
	cin>>n;
	double ans=0;
	for(int i=1;i<=n;i++){
		ans+=(1.0*Que(i+1)/Que(i));
		//cout<<ans<<endl;
	}
	printf("%.4f",ans);
}
int main(){
	test01();
	return 0;
}
