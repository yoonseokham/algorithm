from collections import deque
import sys,heapq
def dataPush(data:tuple):
    return tuple((-data[1],data[0]))
if __name__ == "__main__":
    n=int(input())
    gas_info=deque(sorted([tuple(map(int,sys.stdin.readline().split())) for _ in range(n)]))
    destination,remain_gas=map(int,input().split())
    curLocation=0
    visitCount=0
    gas_station=[]
    while curLocation<destination:
        if curLocation+remain_gas>= destination:
            break
        while gas_info:
            if gas_info[0][0]<=remain_gas+curLocation:
                heapq.heappush(gas_station,dataPush(gas_info[0]))
                gas_info.popleft()
            else:break
        if gas_station:
            temp=heapq.heappop(gas_station)
            cost=-1*temp[0]
            visit=temp[1]
            visitCount+=1
            remain_gas=remain_gas-(visit-curLocation)+cost
            curLocation=visit
        else:
            print(-1)
            exit(0)
    print(visitCount)
