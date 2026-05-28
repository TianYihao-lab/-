from datetime import *

_start=date(2000,1,1)
_end=date(2023,4,21)
_time=timedelta(days=1)

def count(_str):
    _sum=sum(list(map(int,_str)))
    while _sum>=10:
        _sum=sum(list(map(int,str(_sum))))
    return _sum

ans=0
n=int(input())
while _start!=_end:
    _str=f"{_start.year}{_start.month}{_start.day}"
    if count(_str)==n:ans+=1
    _start+=_time
print(ans)