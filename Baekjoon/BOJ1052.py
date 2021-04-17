import heapq

n,k=map(int,input().split())

hq=[1 for i in range(n)]
cnt=0
while len(hq)>k:
    first=heapq.heappop(hq)
    second=heapq.heappop(hq)
    if first==second:
        heapq.heappush(hq,first+second)
    else:
        heapq.heappush(hq,first)
        heapq.heappush(hq,second)
        heapq.heappush(hq,1)
        cnt+=1
print(cnt)
