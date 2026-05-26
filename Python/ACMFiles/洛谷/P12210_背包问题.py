import sys
input=lambda:sys.stdin.readline().strip()

t=int(input())

def test02():       # 尝试使用贪心：失败
    for i in range(t):
        
        b=list(map(int,input().split()))    # 背包的大小
        cntA,cntB=map(int,input().split())    # 每种积木的数量
        vA,vB=map(int,input().split())      # 每种积木所占用的体积
        
        _list=[[cntA,vA],[cntB,vB]]     #[数量,体积]

        b.sort()
        _list.sort(key=lambda i:i[1],reverse=True)
        print(*b)
        print(*_list)
        
        ans=0
        for i in b:
            tmp=i
            for j in range(2):
                while tmp>=_list[j][1] and _list[j][0]>0:
                    ans+=1
                    tmp-=_list[j][1]
                    _list[j][0]-=1
        print(ans)
test02()