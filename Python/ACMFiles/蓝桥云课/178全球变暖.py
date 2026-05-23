n=int(input())
_list=[]
for _ in range(n):
    _list.append(list(map(str,input().strip())))

# for i in _list:print(*i)

vis=[[False]*(n+1) for i in range(n+1)]
dx=[-1,0,1,0]
dy=[0,-1,0,1]
flag=False          # 涨潮后会不会被淹没
def dfs(x,y):       # 这道题就是要看你找到的连通块中存不存在上下左右都有陆地的块
    global flag   
    if _list[x][y]=='.':
        return 
    else:
        vis[x][y]=True

        # 注意到题目说是海域，那么整个图的四周一定是海
        if _list[x+1][y]=='#' and _list[x-1][y]=='#' and _list[x][y+1]=='#' and _list[x][y-1]=='#':
            flag=True       # 这块陆地不会被完全淹没

        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<n and 0<=ny<n and not vis[nx][ny]:
                dfs(nx,ny)  
        return 

ans=0
for i in range(n):
    for j in range(n):
        if not vis[i][j] and _list[i][j]=='#':
            flag=False
            dfs(i,j)
            if not flag:ans+=1
print(ans)