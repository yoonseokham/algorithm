from collections import deque
from itertools import combinations
def strlistToInt(strlist:list)->int:
    return int("".join(strlist))
def intToStrlist(num:int)->list:
    return [i for i in str(num)]
def BFS(startStr:list,count:int)->int:
    swaplist=list(combinations(list(range(len(startStr))),2))
    q=deque([(strlistToInt(startStr),0)])
    evenVisit={strlistToInt(startStr)}
    oddVisit={0}
    if len(startStr)==1 or (len(startStr)==2 and strlistToInt(startStr)%10==0): return -1
    while q:
        curStr,curCount=q.popleft()
        if curCount<count:
            for i,j in swaplist:
                temp=intToStrlist(curStr)
                temp[i],temp[j]=temp[j],temp[i]
                if temp[0]!="0":
                    visit=strlistToInt(temp)
                    if  curCount%2==1 and visit not in evenVisit:
                        evenVisit.add(visit)
                        q.append((visit,curCount+1))
                    if  curCount%2==0 and visit not in oddVisit :
                        oddVisit.add(visit)
                        q.append((visit,curCount+1))
    if count%2==0: return max(evenVisit)
    else: return max(oddVisit)
if __name__=="__main__":
    startStr,count=input().split()
    result=BFS(list(startStr),int(count))
    print(result)
