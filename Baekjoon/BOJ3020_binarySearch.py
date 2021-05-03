import sys

n,h=map(int,input().split())
lower=[]
upper=[]
def BinarySearch(upOrDown:list,target:int)->int:
    start=0
    end=len(upOrDown)-1
    mid=0
    last_cnt=0
    while start<=end:
        mid=(start+end)//2
        if upOrDown[mid]>=target:
            last_cnt=len(upOrDown)-mid
            end=mid-1
        else:
            start=mid+1
    return last_cnt
for i in range(n):
    if i%2==0:
        lower.append(int(input()))
    else:
        upper.append(int(input()))
lower.sort()
upper.sort()
lower_answer=[BinarySearch(lower,i)+BinarySearch(upper,h-i+1) for i in range(1,h+1)]
print(min(lower_answer),lower_answer.count(min(lower_answer)))
