#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
const int N=1e9+5;

// 计算两个电阻并联的等效电阻值
int r1,r2;
void test01(){
    cin>>r1>>r2;
    double ans;
    ans=(1.0*r1*r2)/(r1+r2);
    printf("%.2f",ans);             // 可以用C语言的格式来制定输出的小数点位数
}

// 此函数目前未实现任何功能
void test02(){
    
}
int main(){
    test01();
    return 0;
}