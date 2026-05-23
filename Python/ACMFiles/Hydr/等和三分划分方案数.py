def test01():
    n=int(input())
    _list=[0]+list(map(int,input().split()))
    _Sum=[0]*(n+1)
    for i in range(1,n+1):_Sum[i]=_Sum[i-1]+_list[i]
    # print(*_list)
    # print(*_Sum)
    ans=0
    for i in range(1,n+1):
        for j in range(i+1,n+1):
            if _Sum[i]==_Sum[j]-_Sum[i] and _Sum[j]-_Sum[i]==_Sum[n]-_Sum[j]:
                ans+=1
    print(ans)


def test02():
    n=int(input())
    _list=[0]+list(map(int,input().split()))
    _Sum=[0]*(n+1)
    for i in range(1,n+1):_Sum[i]=_Sum[i-1]+_list[i]
    
    if _Sum[-1]%3!=0:
        print(0)
        return
    else:
        target=_Sum[-1]//3
        l_cnt,ans=0,0   # l_cnt:第一个三分之一点
        for i in range(1,n):
            
            if _Sum[i]==2*target:     # 一定要先判断是不是第二个三分之一点
                # print(ans,l_cnt,end=' ')
                ans+=l_cnt
                # print(ans)

            if _Sum[i]==target:
                l_cnt+=1
    print(ans)
test02()