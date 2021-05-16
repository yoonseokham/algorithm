import sys
import heapq
k,n = map(int,sys.stdin.readline().rstrip().split())
prime = list(map(int,sys.stdin.readline().rstrip().split()))
out=set()
pq=prime[:]
curCount=0
curPrimeNum=0
while curCount<n:
    curPrimeNum=heapq.heappop(pq)
    if curPrimeNum not in out:
        curCount+=1
        out.add(curPrimeNum)
        for i in prime:
            if curPrimeNum*i<2**31:
                heapq.heappush(pq,curPrimeNum*i)
print(curPrimeNum)
