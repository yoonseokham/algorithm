from collections import deque
n=int(input())
m=int(input())
edge=[ list(map(int,input().split())) for i in range(m)]

adj=[[] for i in range(n+1)]
visit=[0 for i in range(n+1)]
cnt=0
for src,dst in edge:
    adj[src].append(dst)
    adj[dst].append(src)

def bfs():
    global visit
    queue=deque([1])
    visit[1]=1
    while queue:
        top=queue.pop()
        if visit[top]==3:
            continue
        for i in adj[top]:
            if visit[i]==0:
                queue.append(i)
                visit[i]=visit[top]+1

bfs()
for i in visit:
    if i !=0:
        cnt+=1
print(cnt-1)
