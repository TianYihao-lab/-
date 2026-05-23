vis=[[False]*11 for i in range(11)]
_list=[]
for i in range(10):
    _list.append(list(map(str,input().strip())))
for i in _list:print(*i)               
def dfs(x,y,z):     # (x,y) z:接受一个字符串
    global ans
    if vis[x][y]:   # 走到走过的路上直接返回
        return      
    vis[x][y]=True
    if x==0 and z=='U':     # 判断能出去的情况
        ans+=1
        return
    if x==9 and z=='D':
        ans+=1
        return
    if y==0 and z=='L':
        ans+=1
        return
    if y==9 and z=='R':
        ans+=1
        return
    
    if z=='U' and x-1>=0:        # 判断进行下一步
        dfs(x-1,y,_list[x-1][y])
    elif z=='D' and x+1<10:
        dfs(x+1,y,_list[x+1][y])
    elif z=='L' and y-1>=0:
        dfs(x,y-1,_list[x][y-1])
    elif z=='R' and y+1<10:
        dfs(x,y+1,_list[x][y+1])

ans=0
for i in range(10):
    for j in range(10):
        vis=[[False]*11 for i in range(11)]
        dfs(i,j,_list[i][j])
print(ans) 