#include<cstdio>
using namespace std;
int main(){
    int n;
    printf("请输入最大边长（必须是单数）："),scanf("%d",&n);
    while(n%2==0){
        printf("请重新输入："),scanf("%d",&n);
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2-i;j++){
            printf(" ");
        }
        for(int k=0;k<2*i+1;k++){
            printf("*");
        }puts("");
    }
    for(int i=0;i<n;i++)printf("*");
    puts("");
   for(int i=n/2+1;i<n;i++){
       for(int j=0;j<i-n/2;j++){
            printf(" ");
        }
        for(int k=0;k<2*(n-i)-1;k++){
            printf("*");
        }puts("");
   }
}