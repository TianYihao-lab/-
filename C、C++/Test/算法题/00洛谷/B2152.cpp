#include<iostream>
using namespace std;
int main(){
    int num,arr[10],cnt=0;
    cin>>num;
    while(num!=0){
        arr[cnt++]=num%10;
        num/=10;
    }
    for(int i=cnt;i>=0;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}