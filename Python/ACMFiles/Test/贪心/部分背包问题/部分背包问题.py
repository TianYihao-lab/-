n,c=map(int,input().split())

_list=[]
for _ in range(n):
    m,v=map(int,input().split())
    _list.append((m,v,v/m))
_list.sort(key=lambda i:i[2],reverse=True)
# print(_list)

_total=0
for i in _list:
    if i[0]<c:
        _total+=i[1]
        c-=i[0]
    else:
        _total+=(i[2]*c)
        break
print(f"{_total:.2f}")