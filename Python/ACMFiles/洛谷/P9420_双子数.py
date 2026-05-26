def test01():
    _str=''
    for i in range(1,2024):
        _str=_str+str(i)
    # print(_str)
    n=len(_str)
    target='2023'
    m=len(target)

    dp=[[0]*(m+1)for _ in range(n+1)]
    for i in range(n+1):dp[i][0]=1

    for i in range(1,n+1):
        for j in range(1,m+1):
            if target[j-1]==_str[i-1]:
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1]
            else:
                dp[i][j]=dp[i-1][j]
    print(dp[n][m])

def E_sieve(n):
    vis = [False] * (n+1)
    primes = []
    for i in range(2, int(n**0.5) + 1):
        if not vis[i]:
            for j in range(i * i, n + 1, i):
                vis[j] = True
    for i in range(2, n + 1):
        if not vis[i]:
            primes.append(i)
    return primes

import math

def test02():
    # print(int(23333333333333**0.5))       # 4830458
    primes = E_sieve(4830458)

    length = len(primes)
    ans = 0

    for i in range(length):
        p = primes[i]
        # 外层剪枝：较小的质数自乘都越界了，直接结束全部查找
        if p * p > 4830459:
            break
        for j in range(i + 1, length):
            q = primes[j]
            # 内层剪枝：一旦乘积超限，直接跳出内层循环
            if p * q >= 4830459:
                break
            target = (p * q) ** 2
            # 判断结果是否在规定区间内
            if 2333 <= target <= 23333333333333:
                ans += 1
    print(ans)

if __name__ == '__main__':
    test02()