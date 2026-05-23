def test():
    n,x=map(int,input().split())
    _list=list(map(int,input().split()))    
    _dict={}
    tmp=0
    _counts=[0]*(n+1)
    for i in range(1,n+1):
        _counts[i]=_counts[i-1]^_list[i-1]

        _dict[_counts[i]]=_dict.get(_counts[i],0)+1

    ans=0
    for i in _counts:
        if i^x in _dict:
            ans+=_dict[i^x]
    print(ans//2)

test()