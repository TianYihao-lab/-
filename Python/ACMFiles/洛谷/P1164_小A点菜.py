n, m = map(int, input().split())
_list = list(map(int, input().split()))

# dp[i][j] 表示前 i 道菜恰好花费 j 元的方案数
dp = [[0] * (m + 1) for _ in range(n + 1)]

# 初始化：0 道菜花费 0 元有 1 种方案
dp[0][0] = 1

for i in range(1, n + 1):
    for j in range(m + 1):
        # 不选第 i 道菜
        dp[i][j] = dp[i-1][j]
        # 选第 i 道菜（如果钱够）
        if j >= _list[i-1]:
            dp[i][j] += dp[i-1][j - _list[i-1]]

print(dp[n][m])