from collections import defaultdict
import sys
import heapq

n,k=map(int,input().split())
diamond=defaultdict(list)
for i in range(n):
    weight,price=map(int,sys.stdin.readline().rstrip().split())
    diamond[weight].append(price)
bag=sorted([ int(sys.stdin.readline().rstrip())  for _ in range(k)])
weightKey=sorted(diamond.keys())
curPush=0
pq=[]
answer=0
for i in bag:
    while curPush<len(weightKey) and weightKey[curPush]<=i:
        for k in diamond[weightKey[curPush]]:
            heapq.heappush(pq,(-k,k))
        curPush+=1
    if pq:
        answer+=heapq.heappop(pq)[1]
print(answer)
