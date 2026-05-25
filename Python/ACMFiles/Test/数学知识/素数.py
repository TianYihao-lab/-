_num=int(input())

def is_prime(x):
    if x!=2 and x%2==0:return False
    for i in range(3,int(x**0.5)+1,2):
        if x%i!=0:return False
    return True

print(is_prime(_num))


# 埃氏筛
vis=[False]*(10**6+1)
prime=[]
def E_sieve(n):
    for i in range(2,int(n**0.5)+1):
        if not vis[i]:
            for j in range(i*i,n+1,i):
                vis[j]=True
    k=0
    for i in range(2,n+1):
        if not vis[i]:
            k+=1
            prime.append(i)
    return k
_count=E_sieve(100)
print(*prime)
print(_count)