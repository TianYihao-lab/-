from math import *
import sys
input=lambda:sys.stdin.readline().strip()
_mod=998244353
ans=0

q=int(input())
for _ in range(q):
    x,y,n=map(int,input().split())
    dp=[[0]*(n+1)for i in range(y-x+1)]
    for i in range(y-x+1):dp[i][0]=1
    
    for i in range(1,y-x+1):
        for j in range(1,n+1):
            if i%x==0 and y%i==0:   # 可以使用这个数
                dp[i][j]=dp[i][j-1]*(i+1)
            else:
                dp[i][j]=dp[i][j-1]
    for i in dp:print(*i)
    print(dp[y-x][n])