def is_prime(m):
  if m!=2 and m % 2 == 0: return False
  for i in range(3, int(m**0.5) + 1, 2):
    if m % i == 0: return False
  return True

m, n = map(int, input().split())
ans=[]
for i in range(m, n + 1):
  if i in ans:continue
  _str=list(str(i))
  reverse_i=int(''.join(_str[::-1]))
  if is_prime(i) and is_prime(reverse_i):
      ans.append(i)
      if m<=reverse_i<=n and i not in ans:ans.append(reverse_i)

length=len(ans)
if length>1:
   for i in range(length-1):
    print(ans[i],end=',')
   print(ans[-1])
else:print('No')