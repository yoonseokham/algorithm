import sys
n=int(input())
moveCost=list(map(int,sys.stdin.readline().rstrip().split()))
oilCost=list(map(int,sys.stdin.readline().rstrip().split()))
startPointer=0
endPointer=0
sum=0
while startPointer<len(oilCost)-1:
    for i in range(startPointer+1,len(oilCost)):
        if oilCost[i]<oilCost[startPointer]:
            endPointer=i
            break
    else:
        endPointer=len(oilCost)-1
    for i in range(startPointer,endPointer):
        sum+=oilCost[startPointer]*moveCost[i]
    startPointer=endPointer
print(sum)
