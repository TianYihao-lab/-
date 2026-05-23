import os
import sys
input=lambda:sys.stdin.readline().strip()
#
m,n=map(int,input().split())
x1,y1,x2,y2=map(int,input().split())

_list=[]
for _ in range(n):
  _list.append(list(input()))
for i in _list:print(*i)
