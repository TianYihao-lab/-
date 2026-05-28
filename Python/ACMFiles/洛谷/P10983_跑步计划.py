from datetime import *

_start=date(2023,1,1)

ans=0
for i in range(365):
    _str=f"{_start.year}{_start.month}{_start.day}"
    _start+=timedelta(days=1)
    # print(_str)
    if '1' in _str or _start.isoweekday()==1:
        ans+=1

print(ans)