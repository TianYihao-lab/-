_list=[0]*(14)
ans=0
def dfs(step):
    global ans
    if step==4:
        if _list[1]+_list[2]!=_list[3]:
            return
    elif step==7:
        if _list[4]-_list[5]!=_list[6]:
            return
    elif step==10:
        if _list[7]*_list[8]!=_list[9]:
            return
    elif step==13:
        if _list[12]*_list[11]==_list[10]:
            ans=ans+1
        return
    for i in range(1,14):
        if i not in _list:
            _list[step]=i
            dfs(step+1)
            _list[step]=0
dfs(1)
print(ans)