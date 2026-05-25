#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<climits>
using namespace std;
#define PI 3.14
const int N=1e5+10;

int arr[10][10];
int _max[6][4],_min[6][4];

void test01(){
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            cin>>arr[i][j];
    
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++){
            if(arr[i][j]>_max[i][3]){
                _max[i][1]=i;
                _max[i][2]=j;
                _max[i][3]=arr[i][j];
            }
        }
            
    for(int i=1;i<=5;i++)
        _min[i][3]=INT_MAX;    // 这里能不能用memset来初始化数组？
    
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            if(arr[j][i]<_min[i][3]){
                _min[i][1]=j;
                _min[i][2]=i;
                _min[i][3]=arr[j][i];
            }
    
    // for(int i=1;i<=5;i++){
    //     cout<<_max[i][1]<<" "<<_max[i][2]<<" "<<_max[i][3]<<endl;
    // }cout<<endl;
    //  for(int i=1;i<=5;i++){
    //     cout<<_min[i][1]<<" "<<_min[i][2]<<" "<<_min[i][3]<<endl;
    // }cout<<endl;
    
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            if(_max[i][1]==_min[j][1]&&_max[i][2]==_min[j][2]&&_max[i][3]==_min[j][3]){
                cout<<_max[i][1]<<" "<<_max[i][2]<<" "<<_max[i][3]<<endl;
                return ;
            }
        }
    }
    
    cout<<"not found"<<endl;
}
int main(){
	test01();
	return 0;
}