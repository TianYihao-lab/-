n=int(input())

# St,En=[0]*(n+1),[0]*(n+1)
# for i in range(n):
#     St[i],En[i]=map(int,input().split())
_list=[]
for i in range(n):
    a,b=map(int,input().split())
    _list.append((a,b))

_list.sort(key=lambda i:i[1])

_now,ans=0,0
for i in _list:
    if _now<=i[0]:
        ans+=1
        _now=i[1]
print(ans)