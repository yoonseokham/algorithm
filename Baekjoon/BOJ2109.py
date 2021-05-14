from collections import defaultdict
import heapq
n=int(input())
pay=defaultdict(list)
pay[0].append(0)
for i in range(n):
    money,day=map(int,input().split())
    pay[day].append(money)
temp=sorted(pay.keys(),reverse=True)
pq=[]
answer=0
for i in range(len(temp)):
    pay[i].sort(reverse=True)
    if temp[i]==0:
        break
    for j in pay[temp[i]]:
        heapq.heappush(pq,(-j,j))
    for j in range(min(len(pq),temp[i]-temp[i+1])):
        answer+=heapq.heappop(pq)[1]
print(answer)
