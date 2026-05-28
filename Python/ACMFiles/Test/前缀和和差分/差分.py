_list=[i for i in range(10)]

_Ext=[0]*len(_list)
for i in range(1,len(_list)):
	_Ext[i]=_list[i]-_list[i-1]
print(*_Ext)

# 将数组中3-8个元素减去1
_Ext[3]-=1
_Ext[9]+=1

_Sum=[0]*len(_list)		# 需要通过一次求前缀和来求原数组的最终值
for i in range(1,len(_Ext)):
	_Sum[i]=_Sum[i-1]+_Ext[i]
print(*_Ext)
print(*_Sum)


# # 将数组中2-9个元素减去1
# _Ext[2]-=1
# _Ext[10]+=1		# ERR,开辟的差分数组的长度不够