n,m,q=map(int,input().split())
_list=[list(map(int,input().split()))for i in range(n)]
# for i in _list:print(*i)

_Sum=[[0]*(m+1)for i in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        _Sum[i][j]=_Sum[i-1][j]+_Sum[i][j-1]-_Sum[i-1][j-1]+_list[i-1][j-1]

def find(x1,y1,x2,y2):
    return _Sum[x1][y1]-_Sum[x2-1][y1]-_Sum[x1][y2-1]+_Sum[x2-1][y2-1]

for _ in range(q):
    x1,y1,x2,y2=map(int,input().split())
    print(find(x2,y2,x1,y1))