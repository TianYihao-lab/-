count=20230610

tmp=1
_count=0
for i in range(1,10000):
    tmp+=i
    _count+=tmp
    print(tmp,_count)
    if _count==count:
        print(i)
        break
    if _count>count:
        print(i-1)
        break
