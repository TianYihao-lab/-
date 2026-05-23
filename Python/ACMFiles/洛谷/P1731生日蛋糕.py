from math import *
n=int(input())
m=int(input())

sk=[0]*(m+1)       # 存放侧面积
vk=[0]*(m+1)       # 存放体积
for i in range(1,m+1):
    sk[i]=sk[i-1]+2*i*i
    vk[i]=vk[i-1]+i*i*i
# sk[i]：前i层都取最小时，侧面积的值
# vk[i]：前i层都取最小时，体积的值

ans=10**19
def dfs(k,r,h,s,v):     # 当前在第k层;上一层的半径;上一层的高度高度;总面积;当前的蛋糕体积
    global ans
    MAX_h=h
    if k==0:
        if v==n:
            ans=min(ans,s)
        return
    if v+vk[k-1]>n:         # 体积不合规，剪枝
        return
    if s+2*(n-v)/r>=ans:    # 面积不合规
        return
     
    for i in range(r-1,k-1,-1):             # 枚举当前层半径i
        if k==m:
            s=i*i       # 上表面的总面积
        MAX_h=min(h-1,(n-vk[k-1]-v)//(i*i))     # 第k-1层的最大高度
        if MAX_h<k:     # 第k层的最低高度为k    
            continue

        for j in range(MAX_h,k-1,-1):       # 枚举高度j
            dfs(k-1,i,j,s+2*i*j,v+i*i*j)

dfs(m,int(sqrt(n))+1,int(sqrt(n))+1,0,0)
if ans==10**19:print(0)
else:print(ans)
# print(ans)