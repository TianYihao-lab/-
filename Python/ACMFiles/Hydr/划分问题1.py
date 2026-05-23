# 这是一道完全背包
n=int(input())
_mod=10**9+7

def test01():
    dp=[[0]*(n+1) for i in range(n+1)]      # dp[i][j]：
    for i in range(n+1):dp[i][0]=1
    # 外层：枚举数字
    for _i in range(1, n + 1):
        # 中层：枚举目标总和
        for _j in range(1, n + 1):
            _k = 0
            # 内层：枚举数字 _i 选了 _k 个
            while _k * _i <= _j:
                dp[_i][_j] = (dp[_i][_j] + dp[_i - 1][_j - _k * _i]) % _mod
                _k += 1
    print(dp[n][n])
test01()


def test02():
    dp=[[0]*(n+1) for i in range(n+1)]      # dp[i][j]：
    for i in range(n+1):dp[i][0]=1
            
    for i in range(1,n+1):      # 枚举数字
        for j in range(1,n+1):      # 枚举目标总和
                if i<=j:
                    dp[i][j]=(dp[i][j-i]+dp[i-1][j])%_mod
                else:
                    dp[i][j]=dp[i-1][j]
    # for i in dp:print(*i)
    print(dp[n][n])