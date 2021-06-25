from collections import deque

n,k=map(int,input().split())
dq=list(range(1,n+1))
answer=[]
next= lambda x: (x+k-1)%len(dq)  
start=0
while dq:
    start=next(start)
    answer.append(str(dq[start]))
    del dq[start]
print("<"+", ".join(answer)+">")
