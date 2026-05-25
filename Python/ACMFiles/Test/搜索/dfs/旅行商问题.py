from math import inf
n=int(input())
_list=[list(map(int,input().split())) for i in range(n)]
vis=[False]*n
vis[0]=True
# for i in _list:print(*i)

ans=inf
def dfs(m,last_city,_sum):
    global ans
    if m==n:
        ans=min(ans,_sum+_list[last_city][0])
        return

    for i in range(n):
        if not vis[i]:
            vis[i]=True
            dfs(m+1,i,_sum+_list[last_city][i])
            vis[i]=False

dfs(1,0,0)
print(ans)