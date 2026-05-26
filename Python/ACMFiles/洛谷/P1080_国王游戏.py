import sys
input=lambda:sys.stdin.readline().strip()

n=int(input())
_l,_r=map(int,input().split())

_list=[]
for i in range(n):
    _list.append(tuple(map(int,input().split())))

# print(_l,_r)
# print(_list,type(_list))
# for i in _list:print(*i,type(i))
_list.sort(key=lambda i:i[0]*i[1])

_max=0
for i in _list:
    _max=max(_max,_l//i[1])
    _l*=i[0]
print(_max)