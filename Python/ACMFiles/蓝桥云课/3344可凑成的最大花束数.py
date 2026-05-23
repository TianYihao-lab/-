from copy import *

n,k=map(int,input().split())
_list=list(map(int,input().split()))
_list.sort()

# def check(mid):         # 检查是否可以凑成mid束花
#     # tmp_list=list         # 使用浅拷贝会出错
#     tmp_list=deepcopy(_list)
#     # print(tmp_list)
#     if len(tmp_list)<k:return False

#     ans=0        # 记录能组成的最大花束数
#     while True:
#         cnt=tmp_list[0]     # 记录第一个位置有多少朵花
#         for i in range(k):
#             tmp_list[i]-=cnt
#         while 0 in tmp_list:
#             tmp_list.pop(0)
#         # print(ans,end=' ')
#         ans+=cnt
#         # print(cnt,ans)
#         if len(tmp_list)<k:break
#         print()
#     return ans>=mid

def check(mid):
    # 判断当前是否能打包成mid束
    cnt = 0
    for i in range(n):
        cnt += min(mid, _list[i])       # 如果够mid朵，就用mid朵，否则用_list[i]朵
    return cnt >= mid * k       #计算的是用了多少花
        
# 二分 符合要求的最大值
l,r=0,max(_list)+1

while l<r:
    _mid=(l+r)>>1
    # print(l,r,_mid)
    if check(_mid):l=_mid+1
    else:r=_mid
# print(l,r)
if l!=0:print(l-1)
else:print(0)