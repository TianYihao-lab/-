import os
import sys
from collections import deque
input=lambda:sys.stdin.readline().strip()

queue=deque()
dx=[-1,0,1,0]
dy=[0,1,0,-1]
n,m=map(int,input().split())
_list=[]
for i in range(n):
  _list.append(list(map(int,input().split())))

# for i in _list:print(*i)
x1,y1,x2,y2=map(int,input().split())
x1,y1,x2,y2=x1-1,y1-1,x2-1,y2-1


def bfs(x,y):
    queue.append((x,y,0))
    _list[x][y]=0
    while queue:
       x,y,steps=queue.popleft()
       for i in range(4):
          nx=x+dx[i]
          ny=y+dy[i]
          
          if 0<=nx<n and 0<=ny<m and _list[nx][ny]==1:
               if nx==x2 and ny==y2:
                  return steps+1
               _list[nx][ny]=0
               queue.append((nx,ny,steps+1))
    return -1

print(bfs(x1,y1))