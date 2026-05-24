#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const int N=1e9+5;
int arr[6];
void test01(){
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    int cnt=0;
    for(int j=0;j<5;j++){
        cnt+=arr[j]%3;
        arr[j]-=(arr[j]%3),arr[j]/=3;
        cout<<arr[j]<<" ";
        arr[(j-1+5)%5]+=arr[j],arr[(j+1)%5]+=arr[j];             // 利用取模找元素时，如果是负数取模需要加上所用空间的大小
        cout<<arr[(j-1+5)%5]<<" "<<arr[(j+1)%5]<<endl;
    }

    for(int k=0;k<5;k++)cout<<arr[k]<<" ";
    puts("");
    cout<<cnt<<endl;
}
int main(){
    test01();
    return 0;
}