#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int N=1e9+5;
long long f;
double lf;
void test01(){
    cin>>f;
    cout<<(int)f<<" "<<(int)(-f)<<endl;   // 只需要去除这个数的小数部分
}
void test02(){
    cin>>lf;
    cout<<floor(lf)<<" "<<ceil(lf)<<" "<<round(lf)<<endl;
     // 这三个函数分别对应 向下取整 向上取整 和 四舍五入
}
int main(){
    //test01();
    test02();
    return 0;
}