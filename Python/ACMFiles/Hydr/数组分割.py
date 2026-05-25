t=int(input())
_mod=10**9+7

for _ in range(t):
    n=int(input())
    _list=[0]+list(map(int,input().split()))
    _total=sum(_list)
    # print(_total)
    if _total%2==1:
        print(0)
        continue
    
    def test01():
        dp=[[0]*(_total+1)for i in range(n+1)]
        for i in range(n+1):dp[i][0]=1

        for i in range(1,n+1):
            for j in range(2,_total+1,2):
                dp[i][j]=dp[i-1][j]
                if j>=_list[i]:
                    dp[i][j]=(dp[i][j]+dp[i-1][j-_list[i]])%_mod

        ans=0
        for i in dp:
            # print(*i)
            for j in i:
                ans+=j
        print(ans-n-1)
    # test01()

    def test02():       # 状态压缩
        dp = [[0] * 2 for _ in range(n + 1)]
            # dp[i][0]:前i个数组合出偶数的方案数
            # dp[i][1]:前i个数组合出奇数的方案数
            
        dp[0][0] = 1
        dp[0][1] = 0

        for i in range(1, n + 1):
            x = _list[i - 1]

            if x % 2 == 0:
                dp[i][0] = (2 * dp[i - 1][0]) % _mod
                dp[i][1] = (2 * dp[i - 1][1]) % _mod
            else:
                s = (dp[i - 1][0] + dp[i - 1][1]) % _mod
                dp[i][0] = s
                dp[i][1] = s

        print(dp[n][0])
    test02()