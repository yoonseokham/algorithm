from collections import defaultdict
import sys

n,h=map(int,input().split())

rock=[int(sys.stdin.readline().rstrip().split()[0]) for i in range(n)]

upper=defaultdict(int)
lower=defaultdict(int)

for j,i in enumerate(rock):
    if j%2==0:
        lower[i]+=1
    else:
        upper[i]+=1
upper_answer=[0 for i in range(h+1)]
lower_answer=[0 for i in range(h+1)]
lowerKey=sorted(list(lower.keys()))
upperKey=sorted(list(upper.keys()))
temp=n//2
i=0
for hi in range(1,h+1):
    if hi<lowerKey[i]:
        lower_answer[hi]=temp
    elif hi==lowerKey[i]:
        lower_answer[hi]=temp
        temp-=lower[hi]
        i+=1
        if i>=len(lowerKey):
            break
temp=n//2
i=0
for hi in range(h,0,-1):
    if h-hi+1<upperKey[i]:
        upper_answer[hi]=temp
    elif h-hi+1==upperKey[i]:
        upper_answer[hi]=temp
        temp-=upper[h-hi+1]
        i+=1
        if i>=len(upperKey):
            break
answer=[lower_answer[i]+upper_answer[i] for i in range(1,h+1)]
temp=min(answer)
print(temp,answer.count(temp))
