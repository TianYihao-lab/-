# 前缀和主要用于题目中对于区间反复求和的问题
_list=[0]+[1,2,3,4,5,6,7,8]
_Sum=[0]*(len(_list))

for i in range(1,len(_list)):
	_Sum[i]=_Sum[i-1]+_list[i]

# print(*_list)
# print(sum(_list))
# print(*_Sum)

# # 求_list[2]+_list[3]+_list[4]+_list[5]  2+3+4+5=14
# print(sum(_list[2:6]))		# 时间复杂度为O(n)
# print(_Sum[5]-_Sum[1])		# 时间复杂度为O(1)

# 求区间 [l, r] 
while True:
    print(f"_list={[i for i in range(9)]}")
    l,r=map(int,input().split())
    print(_Sum[r]-_Sum[l-1])
