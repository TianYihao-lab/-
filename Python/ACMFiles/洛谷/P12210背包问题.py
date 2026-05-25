import sys
input=lambda:sys.stdin.readline().strip()

t=int(input())

for i in range(t):
    b=list(map(int,input().split()))
    cnt=list(map(int,input().split()))
    v=list(map(int,input().split()))

    b.sort(reverse=True)
    v.sort(reverse=True)
    ans=0
    for i in b:
        tmp=i
        while tmp>0:
            for j in range(2):
                if cnt[j]>0:
                    ans+=1
                    tmp-=v[j]
                    cnt[j]-=1
            if cnt[-1]==0 or tmp<v[-1]:break
    print(ans)
        
                    