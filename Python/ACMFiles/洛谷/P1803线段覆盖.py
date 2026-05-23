'''
    贪心：主要的是看出来怎么贪心的
'''

n=int(input())
_list=[]
for _ in range(n):
    start,end=map(int,input().split())
    _list.append((start,end))
# _list.sort(key=lambda i:i[0])
_list.sort(key=lambda i:i[1])

ans,time=0,0
for i in _list:
    if i[0]>=time:
        ans+=1
        time=i[1]
print(ans)