n=int(input())
male=[]
female=[]
for _ in range(n):
    male.append(list(map(int,input().split())))

for _ in range(n):
    female.append(list(map(int,input().split())))

# for i in male:print(*i)
# for i in female:print(*i)

_list=[0]*n
vis=[False]*n
ans=0
def dfs(m):
    global ans
    if m==n:
        _ans=0
        for i in range(n):
            _ans+=(male[i][_list[i]]*female[_list[i]][i])
        ans=max(ans,_ans)

    for i in range(n):
        if not vis[i]:
            _list[m]=i
            vis[i]=True
            dfs(m+1)
            vis[i]=False

dfs(0)
print(ans)