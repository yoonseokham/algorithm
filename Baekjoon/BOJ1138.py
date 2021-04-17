n=int(input())
numList= list(map(int,input().split(" ")))
waitQueue=[n for i in range(n)]
visit=[False for i in range(n)]

for j in range(n):
    cnt=0
    for i in range(n):
        if j+1<waitQueue[i] and cnt<numList[j] and visit[i]==False:
            cnt+=1
        elif cnt==numList[j] and visit[i]==False:
            waitQueue[i]=j+1
            visit[i]=True
            break
for i in waitQueue:
    print(i,end=" ")
