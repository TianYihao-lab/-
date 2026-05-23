from math import *
n=int(input())
_list=[list(map(int,input().split())) for i in range(n)]
# for i in _list:print(*i)

def test01():     # 使用dfs进行暴力
    ans=inf
    _index=[]
    vis=[False]*(n+1)
    
    def solve(m):
        nonlocal ans        # 使用nonlocal代替global关键字
        if m>n:
            # print(*_index,end=' (')
            new_ans=0
            _x,_y,_z=_list[_index[0]][0],_list[_index[0]][1],_list[_index[0]][2]
            # print(_x,_y,_z,end=')(')
            for j in _index[1:]:
                # print(_list[j][0],_list[j][1],_list[j][2],end=')(')
                
                new_ans+=sqrt(pow(abs(_x-_list[j][0]),2)+pow(abs(_y-_list[j][1]),2)+pow(abs(_z-_list[j][2]),2))*_list[j][3]
                # print(tmp)
                _x,_y,_z=_list[j][0],_list[j][1],_list[j][2]
            # print()
            if new_ans<ans:
                ans=new_ans
            return
            
        for i in range(n):
            if not vis[i]:
                vis[i]=True
                _index.append(i)
                solve(m+1)
                _index.pop(-1)
                vis[i]=False
    
    solve(1)
    print("%.2f"%ans)