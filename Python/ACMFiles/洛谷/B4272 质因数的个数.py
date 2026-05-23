import math

n,m=map(int,input().split())

def E_sieve(n):
    visit = [False] * (n + 1)
    prime = []
    sqrt_n = int(math.sqrt(n)) + 1
    for i in range(2, sqrt_n):
        if not visit[i]:
            for j in range(i * i, n + 1, i):
                visit[j] = True
    for i in range(2, n + 1):
        if not visit[i]:
            prime.append(i)
    return prime

prime = E_sieve(m)
# print(prime)

ans=0
for i in range(n,m+1):
      j,cnt=i,0
      for k in prime:
          if j%k==0:
              while j%k==0:
                  cnt+=1
                  j//=k
      ans=max(ans,cnt)
print(ans)