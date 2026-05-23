n,m,t=map(int,input().split())
_list=[[0]]
for _i in range(n):
    _list.append([0]+list(map(int,input())))
# for i in _list:print(*i)

dis=[[float('inf')]*(m+1) for _ in range(n+1)]  # 从起点到(x,y)的需要搬走的最小石头数
vis=[[False]*(m+1) for _ in range(n+1)]     # 标记(x,y)是否已经走过
dx=[-1,0,1,0]
dy=[0,-1,0,1]

def dfs(x,y,cnt):       # 从起点走到任意一点(x2,y2)需要搬走cnt块石头
    if cnt>t:return             # 可行性剪枝     
    if cnt>=dis[x][y]:return    # 记忆化剪枝，当搬走大于dis[x][y]块石头还不能到达(x,y),进行剪枝
    dis[x][y]=cnt       # 更新dis[x][y]为更小的值
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if nx>n or nx<1 or ny>m or ny<1:continue
        if vis[nx][ny]:continue         # 走过的点
        vis[nx][ny]==True
        dfs(nx,ny,cnt+_list[nx][ny])    # 走下一步
        vis[nx][ny]==False

ans=0
for i in range(1,n+1):
    for j in range(1,m+1):
        # 先修复dis和vis两个数组
        dis=[[float('inf')]*(m+1) for _ in range(n+1)]
        vis=[[False]*(m+1) for _ in range(n+1)]

        cnt=1 if _list[i][j]==1 else 0      # 搬走的石头数
        dfs(i,j,cnt)        # 计算从起点(i,j)到 图中其他点 需要般走的石头数量

        for x in range(1,n+1):
            for y in range(1,m+1):
                if dis[x][y]<=t:
                    ans=max(ans,(x-i)**2+(y-j)**2)
print(f'{ans**0.5:.6f}')                    