n,k=map(int,input().split())
cnt=0
def dfs(x,sum,u):
    global cnt
    if u==k:
        if sum==n:cnt+=1
        return
    for i in range(x,int((n-sum)/(k-u))+1):
        dfs(i,sum+i,u+1)

dfs(1,0,0)
print(cnt)