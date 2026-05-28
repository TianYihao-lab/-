n,m,q=map(int,input().split())

_list=[list(map(int,input().split()))for _ in range(n)]

_Exp=[[0 for j in range(m+2)] for i in range(n+2)]
for i in range(1,n+1):
    for j in range(1,m+1):
        _Exp[i][j]=_list[i-1][j-1]-_Exp[i-1][j]-_Exp[i][j-1]+_Exp[i-1][j-1]


def cal(x1,y1,x2,y2,_num):
    _Exp[x1][y1]+=_num
    _Exp[x1][y2+1]-=_num
    _Exp[x2+1][y1]-=_num
    _Exp[x2+1][y2+1]+=_num


def back_sum():
    _Sum=[[0 for j in range(m+2)] for i in range(n+2)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            _Sum[i][j]=_Sum[i-1][j]+_Sum[i][j-1]-_Sum[i-1][j-1]+_Exp[i][j]
    return _Sum

for _ in range(q):
    x1,y1,x2,y2,_num=map(int,input().split())
    cal(x1,y1,x2,y2,_num)

_Sum=back_sum()
for i in range(1,n+1):
    print(' '.join(map(str,_Sum[i][1:m+1])))