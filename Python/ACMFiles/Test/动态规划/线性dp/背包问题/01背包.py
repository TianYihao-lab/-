import sys
input=lambda:sys.stdin.readline().strip()

n,m=map(int,input().split())

_v,_w=[0],[0]   # 体积、价格
dp=[[0]*(m+1) for i in range(n+1)]		

for i in range(n):
    a,b=map(int,input().split())
    _v.append(a)
    _w.append(b)
# for i in range(n):print(_v[i],_w[i])

'''
    dp[i][j]：只考虑前n个物体,在体积不超过j的前提下的最大价值
    我们假设有m个背包
    第一层遍历针对不同的物品
    第二层便利针对不同的背包
    
转移方程：
    dp[i][j]=dp[i-1][j]
    dp[i][j]=max(dp[i-1][j],dp[i-1][j-_v[i]]+_w[i])
'''
for i in range(1,n+1):
    for j in range(1,m+1):
        if _v[i]>j:		# 需要注意，'j-_v[i]'可能是负数，需要进行判断。
            dp[i][j]=dp[i-1][j]
        else:	
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-_v[i]]+_w[i])
print(dp[n][m])