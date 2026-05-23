cnt=0
def dfs(n,_Sum):
  global cnt
  if _Sum==70:
      cnt+=1
  if n==30 or _Sum==100:
    return
  
  dfs(n+1,_Sum+10)
  dfs(n+1,0)  

dfs(0,0)
print(cnt)

# def test01():
#     ans=0
#     def dfs(x,score,k):     
#         global ans

#         if k==0:
#             score=0
#         else:
#             score+=10
#             if score==100:
#                 return
            
#         if score==70:
#             ans+=1

#         if x==30:
#             return
        
#         dfs(x+1,score,0)
#         dfs(x+1,score,1)

#     dfs(0,0,0)
#     print(ans)        