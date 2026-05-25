#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
#define PI 3.14
const int N=1e5+10;

int n,_max,ans;
int arrs[N];

void test01(){
    cin>>n;	
    
    for(int i=1;i<=n;i++){
        cin>>arrs[i];
        _max=max(_max,arrs[i]);
    }
    sort(arrs+1,arrs+n+1);
    int cnt=1;
    while(arrs[cnt]!=_max)ans+=arrs[cnt++];
    cout<<ans<<endl;
}
int main(){
	test01();
	return 0;
}