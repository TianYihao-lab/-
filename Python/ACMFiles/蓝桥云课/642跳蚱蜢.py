from collections import *

_dict=dict()
_dict['123456780']=0
actions=[-1,-2,1,2]

def bfs(s):
    q=deque()
    q.append((s,0,8))

    while q:
        now=q.popleft()
        tmp=now[0]
        if tmp=='876543210':
            # print(_dict[tmp])
            print(now[1])
        _step=now[1]
        _place=now[2]
        for i in range(4):
            _tmp=list(tmp)
            new_place=(_place+actions[i]+9)%9
            _tmp[_place],_tmp[new_place]=_tmp[new_place],_tmp[_place]
            str_tmp=''.join(_tmp)
            if str_tmp not in _dict:
                _dict[str_tmp]=_step+1
                q.append((str_tmp,_step+1,new_place))
    return -1

bfs('123456780')