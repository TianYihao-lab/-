#include<iostream>   // C++语言的标准库
#include<cstdio>     // C语言的标准库
#include<cmath>      // 数学函数库
#include<algorithm>  // 算法函数库
#include<string>     // C++字符串函数库   -- STL库
#include<cstring>    // C风格字符串函数库
using namespace std;  // 命名空间申明
#define PI 3.14
const int N=110;

int n,m;
int arr[N][N];

void test01(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||j==0||i==n-1||j==m-1)
                cout<<arr[i][j]<<" ";
            else
                cout<<round(1.0*(arr[i][j]+arr[i-1][j]+arr[i][j-1]+arr[i+1][j]+arr[i][j+1])/5)<<" ";
        }
        cout<<endl;
    }
}
int main(){
	test01();
	return 0;
}