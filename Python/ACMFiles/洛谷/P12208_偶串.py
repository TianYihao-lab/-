_str=list(input())
_set=set(_str)

# print(_str)
# print(_set)
_flag=True
for i in _set:
    # print(i)
    if _str.count(i)%2==0:
        continue
    else:
        print('NO')
        _flag=False
        break
if _flag:print('YES')