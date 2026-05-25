dp=[[[0]*2023 for i in range(11)]for i in range(2023)]

for i in range(2023):dp[i][0][0]=1

for i in range(1,2023):         # 使用[0,i]这几个数
    for j in range(1,11):       # j:第几个位置
        for k in range(1,2023): # 拼凑出和为k的数
            if k<i:
                dp[i][j][k]=dp[i-1][j][k]
            else:
                dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-i]
print(dp[2022][10][2022])