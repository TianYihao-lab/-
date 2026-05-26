n=int(input())
_list=[]
for i in range(n):
    _list.append(tuple(map(int,input().split())))

_list.sort(key=lambda i:i[0])

ans=0
_l,_r=_list[0][0],_list[0][1]
for i in range(1,n):
    if _r<_list[i][0]:
        ans+=(_r-_l+1)
        _l,_r=_list[i][0],_list[i][1]
    else:
        _r=max(_r,_list[i][1])
        
ans+=(_r-_l+1)
print(ans)