ans = 0
vis = [[False]*7 for i in range(7)]
dx = [0,0,1,-1]
dy = [1,-1,0,0]

def dfs(x,y):   # 注意这里(x,y)不是格子的位置，而是切点的位置
    global ans
    if x == 0 or x == 6 or y == 0 or y == 6:    # 两个切点是对称的，同时结束(只判断一个切点的情况就行)
        ans += 1
        return
    
    vis[x][y],vis[6-x][6-y] = True,True

    for i in range(4):  # 尝试找下一个切点
        tx,ty =x + dx[i], y + dy[i]
        if vis[tx][ty] == 0:
            dfs(tx,ty)
    
    vis[x][y],vis[6-x][6-y] = False,False

dfs(3,3)    # 注意到有一个点一定在切线上(3,3)
print(ans//4)