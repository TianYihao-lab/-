n,x=map(int,input().split())
_list=[0]+list(map(int,input().split()))

_mod=998244353

def test01():       # 暴力
    ans=0
    dp=[[0]*(n+1)for i in range(n+1)]

    for i in range(1,n+1):
        tmp=0
        for j in range(1,n+1):
            tmp^=_list[j]
            if tmp==x:
                ans=(ans+1)%_mod
    print(ans)
# test01()

def test02():
    _dp = [[0] * 64 for _ in range(n + 1)]
    _dp[0][0] = 1         # dp数组初始化，凑成异或和为0的组合，可以不是有任何的数字
    
    for _i in range(1, n + 1):      # 第i个数
        _num = _list[_i - 1] 
        for _j in range(64):        # 异或和为j的方案
            _dp[_i][_j] = (_dp[_i - 1][_j] + _dp[_i - 1][_j ^ _num]) % _mod
            
    print(_dp[n][x])
test02()