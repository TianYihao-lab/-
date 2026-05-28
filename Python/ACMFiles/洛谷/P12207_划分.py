import sys
# lines = sys.stdin.readlines()
# 在数组中选择x个数，使得x(_sum-x)的值最大，进一步推理abs(x-_sum//2)越大
lines = sys.stdin.read().splitlines()		# 消除换行符
_list=[]
for l in lines:
  _list.extend(map(int,l.split()))
# for i in _list:print(i)
# print(_list)
_sum=sum(_list)
_length=_sum//2+1
dp=[[0]*(_length)for i in range(41)]
for i in range(41):dp[i][0]=1

for i in range(1,41):
  for j in range(1,_length):
    # 转移方程
    if j >= _list[i-1]:
        dp[i][j]=dp[i-1][j]+dp[i-1][j - _list[i-1]]
    else:
        dp[i][j]=dp[i-1][j]

for i in range(_length-1,1,-1):
  if dp[40][i]!=0:
    print(i*(_sum-i))
    break