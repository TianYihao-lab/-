def dfs(step,fnum,snum):
    global ans
    if fnum>9 or snum>16:       # 可行性剪枝
        return
    
    if step>7:
        if fnum==9 and snum==16:
            ans+=1
        return
    
    for i in range(6):
        for j in range(6):      
            if i+j>5:       
                break         # 可行性剪枝
            if 2<=i+j<=5:
                dfs(step+1,fnum+i,snum+j)

ans=0
dfs(1,0,0)
print(ans)