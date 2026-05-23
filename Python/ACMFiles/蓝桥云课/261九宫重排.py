from collections import deque

dx=[-1,0,1,0]
dy=[0,-1,0,1]

class Node:
    def __init__(self,s,t):
        self.s=s
        self.t=t
        # print(s,t)

def bfs(s1,s2):
    q=deque()
    q.append(Node(s1,0))
    st=set()
    st.add(s1)
    # print(q)
    while q:
        now=q.popleft()
        ss=now.s
        dist=now.t
        if ss==s2:
            return dist
        k=ss.index('.')
        x=k//3
        y=k%3
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<3 and 0<=ny<3:
                tmp=list(ss)
                # print(*tmp,end=' ')
                tmp[k],tmp[nx*3+ny]=tmp[nx*3+ny],tmp[k]
                tmp=''.join(tmp)
                # print(tmp)
                if tmp not in st:
                    st.add(tmp)
                    q.append(Node(tmp,dist+1))
            else:continue
    return -1
    
s1,s2=input(),input()
print(bfs(s1,s2))