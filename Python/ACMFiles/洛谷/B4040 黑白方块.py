t=int(input())

for _ in range(t):
    n,m=map(int,input().split())

    _list=[]
    for _i in range(n):
        _list.append(list(map(int,input())))

    if n<4 or m<4:
        print('No')
        continue
    else:
        flag = False
        for i in range(n - 3):
            if flag:
                break
            for j in range(m - 3):
                if i+3<n and j+3<m and\
                   _list[i][j] == 0 and _list[i][j+1] == 0 and _list[i][j+2] == 0 and _list[i][j+3] == 0 and \
                   _list[i+1][j] == 0 and _list[i+1][j+1] == 1 and _list[i+1][j+2] == 1 and _list[i+1][j+3] == 0 and \
                   _list[i+2][j] == 0 and _list[i+2][j+1] == 1 and _list[i+2][j+2] == 1 and _list[i+2][j+3] == 0 and \
                   _list[i+3][j] == 0 and _list[i+3][j+1] == 0 and _list[i+3][j+2] == 0 and _list[i+3][j+3] == 0:
                    print('Yes')
                    flag = True
                    break
        if not flag:
            print('No')