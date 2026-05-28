_set=['1111110','0110000','1101101','1111001','0110011','1011011','1011111','1110000','1111111','1111011']
# _set=set(_set)
# print(_set,type(_set))

# ans=1
# for _ in range(18):
#     tmp_ans=1
#     _str=input()
#     length=len(_str)
#     for i in range(length):
#         if _str[i]=='0':
#             tmp_str=list(_str)
#             tmp_str[i]='1'
#             tmp=''.join(tmp_str)
#             if tmp in _set:
#                 tmp_ans+=1
#     print(tmp_ans,end=' ')
#     ans*=tmp_ans
#     print(ans)
# print(ans)

ans=1
for _ in range(18):
    _str=input()
    tmp_ans=10
    for j in _set:
        for i in range(7):
            if _str[i]=='1' and j[i]=='0':tmp_ans-=1;break
    ans*=tmp_ans
print(ans)