import sys
input=lambda:sys.stdin.readline().strip()

n, m = map(int, input().split())
V = [0]*(n+1)
W = [0]*(n+1)

for i in range(1,n+1):
    V[i], W[i] = map(int, input().split())

dp=[[0]*(m+1)for i in range(n+1)]
def test01():   
    # 先遍历每个物品
    for i in range(1,n+1):
        # 再遍历每个背包
        for j in range(1,m+1):
            dp[i-1][j]=dp[i-1][j]
            for k in range(j//V[i]+1):
                dp[i][j]=max(dp[i][j],dp[i-1][j-k*V[i]]+k*W[i])
    
    print(dp[n][m])

test01()