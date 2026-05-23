# 这是一道01背包的问题
n=int(input())
_mod=10**9+7
'''
    算法核心思想标签：二维动态规划，0-1背包求方案数
    题目描述：给定正整数 n，将其划分为若干个严格递减的正整数之和，求有多少种不同的划分方案。
    输入格式：输入一行，包含一个正整数 n (1 <= n <= 1000)。
    '''
def test01():
    dp=[[0]*(n+1) for i in range(n+1)]
        # dp[i][j]  # 仅考虑使用前i个正整数，凑出和恰好为j的方案数
    for i in range(n+1):dp[i][0]=1

    for i in range(1,n+1):
        for j in range(1,n+1):
            if i>j:         # 
                dp[i][j]=dp[i-1][j]
            else:
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-i])%_mod
    for i in dp:print(*i)
    print(dp[n][n])
test01()

def test02():       # 这里使用了 滚动数组
    dp=[0]*(n+1)
    dp[0]=1    # 开始时，凑出和为0的方案数的个数是1

    for i in range(1,n+1):
        for j in range(n,i-1,-1):
            dp[j]=(dp[j]+dp[j-i])%_mod

    print(dp[n])
# test02()      
