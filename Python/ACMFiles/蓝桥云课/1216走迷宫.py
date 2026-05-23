from collections import *

n,m=map(int,input().split())
_list=[[0]*6]
for _ in range(n):
    _list.append([0]+list(map(int,input().split())))
# for i in _list:print(*i)

x,y,_x,_y=map(int,input().split())

dx=[0,-1,0,1]
dy=[1,0,-1,0]
_dict=dict()
def bfs(x,y,step):
    _dict[(x,y)]=step
    q=deque()
    q.append((x,y))
    while(q):
        x,y=q.popleft()
        if x==_x and y==_y:
            # print(_dict[(x,y)])
            return _dict[(x,y)]
        step=_dict[(x,y)]+1
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<nx<=n and 0<ny<=m and (nx,ny) not in _dict and _list[nx][ny]==1:
                _dict[(nx,ny)]=step
                q.append((nx,ny))
    return -1

print(bfs(x,y,0))