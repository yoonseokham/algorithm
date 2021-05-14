from collections import defaultdict
n=int(input())
m=int(input())
weight=defaultdict(list)
visit=[[0 for i in range(n+1)] for i in range(n+1)]
def DFS(weight:defaultdict,visit:list,start:int,cur:int):
    visit[start][cur]=1
    for i in weight[cur]:
        if visit[start][i]==0:
            DFS(weight,visit,start,i)
for i in range(m):
    start,end=map(int,input().split())
    weight[start].append(end)
for i in range(1,n+1):
    DFS(weight,visit,i,i)
for i in range(1,n+1):
    count=1
    for j in range(1,n+1):
        if i!=j:
            count+=visit[i][j]
            count+=visit[j][i]
    print(n-count)
