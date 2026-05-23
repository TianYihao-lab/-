# print(7656237)
# 白旗先走(棋盘上有13个白旗和12个黑棋)
rows=[0]*5
cols=[0]*5
main_s=0    # 主对角线
remain_s=0  # 副对角线

ans=0
def dfs(m,step):    # m：一共有多少个白棋,step：下到第几步
    global ans,main_s,remain_s
    if step==25:
        if m==13 and \
            0 not in rows and 0 not in cols and main_s!=0 and remain_s!=0 and\
            5 not in rows and 5 not in cols and main_s!=5 and remain_s!=5:
            ans+=1
        return
    
    if m + (25 - step)<13:      # 下不到13个白棋
        return
    if step-m>12:               # 黑棋的个数大于12个
        return
        
    dfs(m,step+1)
    _x,_y=divmod(step,5)
    rows[_x],cols[_y]=rows[_x]+1,cols[_y]+1
    if _x+_y==4:remain_s+=1
    if abs(_x-_y)==0:main_s+=1
    dfs(m+1,step+1)
    rows[_x],cols[_y]=rows[_x]-1,cols[_y]-1
    if _x+_y==4:remain_s-=1
    if abs(_x-_y)==0:main_s-=1

dfs(0,0)   
print(ans)