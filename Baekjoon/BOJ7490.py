from copy import deepcopy
nums=[int(input()) for i in range(int(input()))]

def recursive_brute(cnt:int ,length:int,curList:list,answer:list)->list:
    iter=["","+","-"]
    if length==cnt:
        a=deepcopy(curList)
        answer.append(a)
    else:
        for i in iter:
            curList.append(i)
            recursive_brute(cnt+1,length,curList,answer)
            curList.pop()
for i in nums:
    answer=[]
    recursive_brute(0,i-1,[],answer)
    temp=list(range(1,i+1))
    for i in answer:
        i.append("")
        result=[str(temp[k])+i[k] for k in range(len(i))]
        forPrint=[str(temp[k])+i[k] if len(i[k])==1 and k!=len(i)-1  else str(temp[k])+i[k]+" " for k in range(len(i))]
        result=''.join(result)
        if eval(result)==0:
            print(''.join(forPrint))
    print()
