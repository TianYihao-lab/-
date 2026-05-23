#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
#define N 1e5+10
#define PI 3.14

int n,x2,y2,x,y;

void test01(){
	cin>>n>>x2>>y2;
	float temp=1.0*y2/x2,temp2=0; // temp代表的是鸡尾酒疗法的疗效 	
	//temp=(int)(100*temp);
	//cout<<temp<<" ";
	
	while(n--){
		cin>>x>>y;
		temp2=1.0*y/x;     //temp2代表的是新疗法的疗效
		//temp2=(int)(100*temp2);
		//cout<<temp2<<endl;
		
//		if(temp==temp2)cout<<"same"<<endl;
//		if(temp>temp2)cout<<"worse"<<endl;
//		if(temp<temp2)cout<<"better"<<endl;
		//cout<<temp<<" "<<temp2<<endl;
		if(temp-temp2>0.05&&temp>temp2)cout<<"wrose"<<endl;
		else if(temp2-temp>0.05&&temp2>temp)cout<<"better"<<endl;
		else cout<<"same"<<endl;
	}
	return ;
}
int main(){
	test01();
	return 0;
}
