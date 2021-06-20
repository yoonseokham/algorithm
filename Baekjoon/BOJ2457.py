import sys
from collections import deque
def monthDayToDay(month:int,day:int)->int:
    return day+sum([0,31,28,31,30,31,30,31,31,30,31,30,31][:month])
if __name__ == "__main__":
    n=int(input())
    line=[]
    princeseStartDay=monthDayToDay(3,1)
    princeseEndDay=monthDayToDay(11,30)+1
    for _ in range(n):
        startMonth,startDay,endMonth,endDay=map(int,sys.stdin.readline().rstrip().split())
        line.append((monthDayToDay(startMonth,startDay),monthDayToDay(endMonth,endDay)))
    curEndDay=princeseStartDay
    flowers=deque(sorted([i for i in line if i[1]>=princeseStartDay and i[0]<=princeseEndDay],key=lambda x:(x[1],x[0])))
    count=0
    while curEndDay<princeseEndDay:
        maxEndIndex=-1
        for i,(start,end) in enumerate(flowers):
            if start<=curEndDay:
                maxEndIndex=i
        if maxEndIndex==-1 or not flowers:
            print(0);exit(0)
        curEndDay=flowers[maxEndIndex][1]
        count+=1
        for _ in range(maxEndIndex+1):
            flowers.popleft()
    print(count)
