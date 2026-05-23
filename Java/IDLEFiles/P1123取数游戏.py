t=int(input())

dx=[1,1,1,0,0,-1,-1,-1]
dy=[1,0,-1,1,-1,1,0,-1]

def dfs(step):
        global n
        global m
        global _max

        if step==n*m:
            tmp_max=0
            for i in range(step):
                _x,_y=i//m,i%m
                if vis[_x*m+_y]:tmp_max+=_list[_x][_y]
            _max=max(_max,tmp_max)
            return
        
        vis[step]=False
        dfs(step+1)
        _x,_y=divmod(step,m)
        for i in range(8):
            tmp_x,tmp_y=_x+dx[i],_y+dy[i]
            if 0<=tmp_x<n and 0<=tmp_y<m:
                if vis[tmp_x*m+tmp_y]:return
        vis[step]=True
        dfs(step+1)
        return

for _ in range(t):
    n,m=map(int,input().split())
    _list=[list(map(int,input().split())) for _i in range(n)]
    _max=0
    vis=[False]*(n*m)
    dfs(0)
    print(_max)
