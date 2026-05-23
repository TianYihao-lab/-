def test01():       # 暴力
    n,m,x=map(int,input().split())
    _list=[0]+list(map(int,input().split()))
    for _ in range(m):
        l,r=map(int,input().split())
        flag=False
        for i in range(l,r+1):
            if flag:break
            for j in range(i+1,r+1):
                if _list[i]^_list[j]==x:
                    print('yes')
                    flag=True
                    break
        if not flag:print('no')
# test01()

def test02():
    n,m,x=map(int,input().split())
    _list=list(map(int,input().split()))

    for _ in range(m):
        l,r=map(int,input().split())
        # 考虑到异或的性质
        flag=False
        for i in range(l-1,r):
            if x^_list[i] in _list[l-1:r]:
                # print(_list[i],_list[i]^x,x)
                flag=True
                break
        print('yes' if flag else 'no')
test02()