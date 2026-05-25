a,b=map(int,input().split())

def fastpow01(a,b,_mod=10**9+7):
    if b==0:return 1
    if b==1:return a
    cnt=fastpow01(a,b//2,_mod)
    if b%2==1:return ((cnt*cnt)*a)%_mod
    else:return (cnt*cnt)%_mod

def fastpow02(a,b,_mod=10**9+7):
    ans=1
    while b:
        if b&1:ans*=a
        a=(a*a)%_mod
        b>>=1
    return ans%_mod

print(f'a**b={fastpow01(a,b)}')
print(f'a**b={fastpow02(a,b)}')