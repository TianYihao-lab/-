_list=[0,5,5,10,10,15,15,20,20,25,25]
vis=[False]*11
_set=set()
ans=0
def dfs(n,_sum):
    global ans
    if n>10:
        if _sum not in _set:
            _set.add(_sum)
            ans+=1
        return

    dfs(n+1,_sum+_list[n])
    vis[n]=True
    dfs(n+1,_sum)
    vis[n]=False

dfs(1,0)
print(ans)