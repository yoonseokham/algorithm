import heapq
import sys
n=int(input())
temp=[]

for i in range(n):
    a=int(sys.stdin.readline().rstrip())
    if a != 0 :
        heapq.heappush(temp,-a)
    elif a == 0 :
        if len(temp)==0:
            print(0)
        else:
            print(-heapq.heappop(temp))
            
