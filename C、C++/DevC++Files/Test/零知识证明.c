#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

long long mod_pow(long long base, long long exp, long long mod){
    long long result=1;
    base=base%mod;
    while(exp>0){
        if(exp%2==1){
            result=(result*base)%mod;
        }
        base=(base*base)%mod;
        exp=exp>>1;
    }
    return result;
}

int zero_knowledge_proof(long long G,long long Q,long long P,long long x,long long y ){
    // 证明者需要一个随机数r
    long long r=rand()%(Q-1)+1;
    long long C=mod_pow(G, r, P);   //G^r mod P

    // 服务器端
    long long e=rand()%(Q-1)+1;
    
    // 设备端
    long long s=(r+e*x)%Q;

    // 服务器验证结果
    long long left=mod_pow(G, s, P);
    long long right=(C*mod_pow(y, e, P))%P;
    printf("\n认证阶段\n");
    printf("1.设备发送承诺制C=%lld^%lld mod %lld\n", G, r, P);
    printf("2.服务器发送挑战e=%lld\n", e);
    printf("3.设备发送响应s=%lld\n", s);
    printf("\n[验证阶段]\n");
    printf("验证等式：G^s mod P == C * y^e mod P\n");
    printf("服务器验证 %lld == %lld\n", left, right);

    if(left == right)
        printf("验证成功\n");
    else
        printf("验证失败\n");

    //return left==right;
}
int main(){
    srand(time(0));

    long long G=2;
    long long P=23;
    long long Q=11;
    
    // 验证端（设备端）
    long long x=rand()%(Q-1)+1;     // 私钥
    long long y=mod_pow(G, x, P);   // 公钥 y=G^x mod P

    for(int i=0; i<5; i++){
        zero_knowledge_proof(G, Q, P, x, y),printf("\n");
    }
    
    return 0;
}