import heapq
from collections import defaultdict

n=int(input())
db=[tuple(map(int,input().split())) for i in range(n)]


db.sort(key=lambda x: (-x[1],x[0]))
DayAndReward=defaultdict(list)
for i,j in db:
    DayAndReward[i].append(j)
Day=sorted(DayAndReward.keys(),reverse=True)
Day.append(0)
home_work=[]
answer=0
for i in range(0,len(Day)-1):
    for j in DayAndReward[Day[i]]:
        heapq.heappush(home_work,-j)
    pick=0
    while home_work and pick<Day[i]-Day[i+1]:
        answer-=heapq.heappop(home_work)
        pick+=1
print(answer)
