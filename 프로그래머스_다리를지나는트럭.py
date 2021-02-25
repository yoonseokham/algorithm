from collections import deque
def solution(bridge_length, weight, truck_weights):
    q=deque(truck_weights)
    passing=deque([])
    sum=0
    cnt=0
    while q or passing:
        if q and sum+q[0]<=weight:
            sum+=q[0]
            passing.append([q.popleft(),cnt])
        cnt+=1
        if cnt!=0 and cnt-passing[0][1]==bridge_length:
            sum-=passing.popleft()[0]
    return cnt+1
