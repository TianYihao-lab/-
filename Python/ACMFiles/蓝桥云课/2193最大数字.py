n,a,b=map(int,input().split())
_list=[int(i) for i in str(n)]
# print(_list)

ans=0
def dfs(m,last_step):       # m:正在处理第几位数；last_step:上一步的数是多少
    global a,b,ans
    if m==len(_list):
        ans=max(ans,last_step)
        return
    d=_list[m]          # 第m位上的数是多少
    
    # 尝试1号操作
    t=min(a,9-d)        # 需要多少次1号操作(目前还有多少次1号操作)
    a-=t
    dfs(m+1,10*last_step+d+t)   
    a+=t                # 恢复现场
    
    # 尝试2号操作
    if b>d:             # 确认操作2能否减小到 9
        b-=(d+1)        # 减小到 9 一共需要 d+1 次操作
        dfs(m+1,10*last_step+9)
        b+=(d+1)        # 恢复现场

dfs(0,0)
print(ans)