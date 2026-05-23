#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b<=c||a+c<=b||b+c<=a){
        printf("No solution.");
        return 0;
    }
    double s=(a+b+c)/2.0;
    double res=s*(s-a)*(s-b)*(s-c);
    printf("%.2lf",sqrt(res));
    getchar();
    return 0;
}
