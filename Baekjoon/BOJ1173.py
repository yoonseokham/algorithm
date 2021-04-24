import sys
N,m,M,T,R=map(int,sys.stdin.readline().rstrip().split())
x=m
cnt=0
totalCount=0
if m+T>M:
    print(-1)
    sys.exit(0)
while cnt<N:
    if x+T<=M:
        x+=T
        cnt+=1
    else:
        x=max(m,x-R)
    totalCount+=1
print(totalCount)
