n=int(input())

cols=[False]*n
main_diag=[False]*(2*n-1)
anti_diag=[False]*(2*n-1)

ans=0
def dfs(rows):
    global ans
    if rows==n:
        ans+=1
        return
    
    for i in range(n):
        if not cols[i] and not main_diag[n-1+rows-i] and not anti_diag[rows+i]:
            cols[i]=True
            main_diag[n-1+rows-i]=True
            anti_diag[rows+i]=True
            dfs(rows+1)
            cols[i]=False
            main_diag[n-1+rows-i]=False
            anti_diag[rows+i]=False

dfs(0)
print(ans)