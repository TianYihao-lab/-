n,v=map(int,input().split())

_w=[0]      # 物体的体积
_v=[0]      # 物体的价值
f=[[0]*(v+1) for i in range(n+1)]

for i in range(n):
    a,b=map(int,input().split())
    _w.append(a)
    _v.append(b)

for i in range(1,n+1):
    for j in range(1,v+1):
        if j-_w[i]>=0:  # 这个货物可以选，也可以不选
            f[i][j]=max(f[i-1][j],f[i-1][j-_w[i]]+_v[i])
        else:           # 这个货物不能选
            f[i][j]=f[i-1][j]
print(f[n][v])