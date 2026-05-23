def dfs(step,fnum,snum):	# step:第几步  fnum:第一种糖果数量 snum:第二种糖果数量
    global ans
    if fnum>9 or snum>16:       # 可行性剪枝,分出去的糖果数量不会超过总糖果数
        return
    
    if step>7:					# 结束
        if fnum==9 and snum==16:  ans+=1
        return
    
    for i in range(6):
        for j in range(6):      
            _index=i+j
            if 2<=_index<=5:           
                dfs(step+1,fnum+i,snum+j)
            if _index>5:break
ans=0
dfs(1,0,0)
print(ans)