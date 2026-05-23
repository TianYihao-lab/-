import sys
input=lambda:sys.stdin.readline().strip()

n,m,c=map(int,input().split())
_list=[list(map(int,input().split()))for i in range(n)]
# print(_list)
# for i in _list:
#   print(*i)

_counts=[[0]*(m+1) for _ in range(n+1)]
# print(*_counts)
# for i in _counts:
#   print(*i)

for i in range(1,n+1):
  for j in range(1,m+1):
    _counts[i][j]=_list[i-1][j-1]+_counts[i][j-1]+_counts[i-1][j]-_counts[i-1][j-1]
# print(*_counts)
# for i in _counts:
#   print(*i)

def Cal(x,y,m,n):
  return _counts[x][y]-_counts[x][n-1]-_counts[m-1][y]+_counts[m-1][n-1]

ans,x0,y0=0,0,0
for i in range(1,n+1-c):
  for j in range(1,m+1-c):
    tmp=Cal(i+c-1,j+c-1,i,j)
    if ans<tmp:
      ans=tmp
      x0,y0=i,j
print(i,j)