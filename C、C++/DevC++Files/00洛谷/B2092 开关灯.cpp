#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
#define PI 3.14
const int N=1e5+10;

int n;
int arrs[N];

void test01(){
    cin>>n;
    fill(arrs+1,arrs+n+1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j%i==0)arrs[j]=0-arrs[j];
        }
    }
    for(int i=1;i<=n;i++)if(arrs[i]==-1)cout<<i<<" ";
}
int main(){
	test01();
	return 0;
}