# def test01():
#     a,b=input().split()
#     print(a,b)
#     a=input().split()		# 这里数组存储的内容都是字符串
#     print(a)                # ['1', '2', '3']
#     b=list(map(int,input().split()))	# 这里数组存储的内容是数字
#     print(b,type(b[0]))     # [1, 2, 3]

# # test01()

# def test02():
#     a,b,c=map(int,input())	# 相当于 a,b=int(input()),int(input())
#     print(a,b,c,type(a))

#     s = list(input())
#     print(s,type(s[0]))

#     a=list(map(int,input()))
#     print(a,type(a[0]))

#     # 使用strip可以移除掉可能存在的空格或者换行，更加安全
#     s = list(input().strip())
#     print(s,type(s[0]))

#     s = list(map(int,input().strip()))
#     print(s,type(s[0]))

# # test02()

from collections import deque
n=int(input())
s=list(input())
q=deque()

while True:
  # if n%2==1:print('No');break   # 只有长度为偶数的括号串才能配对
  a=s.pop()
  # print(a,' ',s)
  if a==')':q.appendleft(a)
  else:
    if q:                                                                          
      b=q.popleft()
      if b=='(':continue    # 配对成功，继续循环
    else: print('No');break
    
  if len(s)==0 and len(q)==0 :print('Yes');break   # 括号串全部出列时，结束循环