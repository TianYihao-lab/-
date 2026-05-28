def test():
    ans=0
    for i in range(1,1000001):
        tmp=i
        tmp_str=list(str(tmp))
        
        # print(tmp_str)
        _dict={}
        for j in tmp_str:
            _dict[j]=_dict.get(j,0)+1

        
        for j in range(2,int(i**0.5)+1):
            if i%j==0:
                res=i//j
                j_str,res_str=list(str(j)),list(str(res))
                _list=j_str+res_str

                _dict02=dict()
                for j in _list:
                    _dict02[j]=_dict02.get(j,0)+1

                _set=set(_list)
                flag=True
                for j in _set:
                    if j not in _dict or j not in _dict02 or _dict[j]!=_dict02[j]:
                        flag=False
                if flag:ans+=1;break
    print(ans)
# test()

def test01():
    ans=0
    for i in range(1,1000001):
        tmp=i
        tmp_str=sorted(list(str(tmp)))

        
        for j in range(2,int(i**0.5)+1):
            if i%j==0:
                res=i//j
                j_str,res_str=list(str(j)),list(str(res))
                _list=sorted(j_str+res_str)
                
                if tmp_str==_list:ans+=1;break
        
    print(ans)
test01()