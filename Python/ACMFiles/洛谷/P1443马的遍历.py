from collections import deque
dx=[2,1,-1,-2,-2,-1,1,2]
dy=[1,2,2,1,-1,-2,-2,-1]
'''
    一道标准的BFS题目

'''
n,m,u,v=map(int,input().split())

class Node:
    def __init__(self,x,y):
        self.x=x
        self.y=y

dis=[[-1]*(m+1) for _ in range(n+1)]        # 最短路径的长度
vis=[[False]*(m+1) for _ in range(n+1)]     # 是否存在最短路径
# pre=[[None]*(m+1) for _ in range(n+1)]

s=Node(u,v)
dis[s.x][s.y]=0
vis[s.x][s.y]=True
q=deque([s])
while q:
    now=q.popleft()
    for i in range(8):
        nx,ny=now.x+dx[i],now.y+dy[i]
        if nx<1 or nx>n or ny<1 or ny>m or vis[nx][ny]:
            continue
        vis[nx][ny]=True
        dis[nx][ny]=dis[now.x][now.y]+1
        # pre[nx][ny]=now
        q.append(Node(nx,ny))
    
for i in range(1,n+1):
    for j in range(1,m+1):
        print(f"{dis[i][j]}",end=' ')
    print()