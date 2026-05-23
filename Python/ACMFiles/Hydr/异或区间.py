def test01():       # 暴力
    n,x=map(int,input().split())
    _list=[0]+list(map(int,input().split()))

    _Sum=[0]*(n+1)
    for i in range(1,n+1):
        _Sum[i]=_Sum[i-1]^_list[i]

    ans=0
    for i in range(1,n+1):
        for j in range(i+1,n+1):
            if _Sum[i]^_Sum[j]==x:
                ans+=1
    print(ans)

def test02():
        n,x=map(int,input().split())
        _list=[0]+list(map(int,input().split()))

        _Sum=[0]*(n+1)
        for i in range(1,n+1):
            _Sum[i]=_Sum[i-1]^_list[i]
        # print(*_Sum)

        ans=0
        for i in range(1,n+1):
            if _Sum[i]^x in _Sum[:i]:
                # print(_Sum[i],_Sum[i]^x)
                ans+=_Sum.count(_Sum[i]^x)
        print(ans)
        
test02()